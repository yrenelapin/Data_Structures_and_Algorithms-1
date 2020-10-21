/*
BMP - bitmap image file
BMP file - Picture Format , Simplest
It is usually uncompressed file format.But due to change in lot of Versions of BMP file format,
Some Newer BMP file formats even had Compression involved..

But we are dealing with only those which dont have Compression in this Code.

zip,gif are Compressed -- They use Huffman Coding
jpeg - Advanced Compression - Humans cant distinguish certain colors.

Refer the Wikipedia Page of BITMAP File We have created the Below Structures.
*/

#include <stdio.h>
#include <stdlib.h>


struct BITMAP_header{

    char name[2];               // this should be equal to BM
    unsigned int size ;         // Using int because sizeof(int)==4 in my laptop.
    int garbage;                // Unwanted details
    unsigned int image_offset;  //Offset from where the Image starts in a file.

};

struct DIB_header{

    unsigned int header_size ;      // Size of this header
    unsigned int width;
    unsigned int height;
    unsigned short int colorplanes;
    unsigned short int bitsperpixel;
    unsigned int compression;       // 0 if No Compression is present
    unsigned int image_size;
    unsigned int temp[4];
};


struct RGB {

    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

struct Image
{
    int height;
    int width;
    struct RGB **rgb;       // For allocating memory dynamically for 2D ARRAY

};



struct Image readImage(FILE *fp, int height, int width){
    int i ;
    int bytestoread;
    struct Image pic ;

    pic.rgb = (struct RGB**) malloc(height*sizeof(void*));
    pic.height = height ;
    pic.width = width;

    // To account for Padding.. Refer Formulae in Wikipedia
    bytestoread= ((24* width + 31)/32)*4 ;
    int numOfrgb =  bytestoread/sizeof(struct RGB) + 1 ;

    // To make picture from Top to Bottom we are indexing from height-1
    for (i=height-1;i>=0;i--){
        pic.rgb[i] = (struct RGB *) malloc(numOfrgb*sizeof(struct RGB));
        fread(pic.rgb[i], 1 , bytestoread,fp);
    }

    return pic;
}

void freeImage(struct Image pic){
    int i ;
    for (i=pic.height-1;i>=0;i--){ free(pic.rgb[i]); }
    free(pic.rgb);
}


unsigned char grayscale(struct RGB rgb){

    return (  (0.3*rgb.red) + (0.6*rgb.green)+(0.1*rgb.blue));
}

void RGBImageToGrayscale(struct Image pic){
    int i,j;
    for(i=0;i<pic.height;i++)
        for(j=0;j<pic.width;j++)
            pic.rgb[i][j].red = grayscale(pic.rgb[i][j]);
            pic.rgb[i][j].blue = grayscale(pic.rgb[i][j]);
            pic.rgb[i][j].green = grayscale(pic.rgb[i][j]);

}


// TEXT ART

void imagetotext(struct Image img){
    int i,j;
    unsigned char gs;
    
    // 0-31, 32-63, 64-95, 96-127,...
    
    char textpixel[]= {'@','#','%','O','a','-','.',' '};

    for(i=0;i<img.height;i++){
        for(j=0;j<img.width;j++ ){
            gs = grayscale(img.rgb[i][j]);
            // Inverting to appear in BLACK colored Terminal !
            printf("%c",textpixel[7-gs/32]);

        }
        printf("\n");
    }

}


int createBWImage(struct BITMAP_header header,struct DIB_header dibheader,struct Image pic){

    int i ;

    FILE *fpw = fopen("new.bmp","w");
    if (fpw == NULL ) return 1;

    RGBImageToGrayscale(pic);

    fwrite(header.name,2,1,fpw);
    fwrite(&header.size, 3*sizeof(int),1,fpw);
    fwrite(&dibheader,sizeof(struct DIB_header),1,fpw);

    for (i=pic.height-1;i>=0;i--){ fwrite(pic.rgb[i],((24* pic.width + 31)/32)*4, 1 ,fpw);
    }

    fclose(fpw);
    return 0;

}



int openbmpfile(char *filename){

    // When ever we are using non text files for reading We use "rb" instead of "r" where "b" stands for BINARY

    FILE *fp = fopen(filename,"rb");

    if (fp==NULL) return 1;

    struct BITMAP_header header;
    struct DIB_header dibheader;


    // printf("%d,\n",sizeof(BITMAP_header));
    
    // It will be 16(Though it should be 14) becoz C uses equal spaces for all elements in the Structure.. Since all have size 4 except name, It uses 4 bytes for name also for EFFICIENCY PURPOSE.


    // Reading a binary file is done using fread() unlike fscanf() for text files    
    // fread(where to store, size, number of quantities, pointer)

    // fread(&header,sizeof(struct BITMAP_header), 1, fp);    
    // Due to the problem faced by us as C uses extra memory allocation as mentioned earlier, We read data using two separate fread() 's as shown below

    fread(header.name,2,1,fp);
    fread(&header.size, 3*sizeof(BITMAP_header),1,fp);

    printf("First two characters:%c%c \n",header.name[0],header.name[1]);

    if ((header.name[0] !='B') || ( header.name[1]!='M')){fclose(fp); return 1 ;}

    printf("Size of the file :%d \n",header.size);
    printf("Offset: %d\n",header.image_offset);
    printf("%d",123111);

    fread(&dibheader,sizeof(struct DIB_header), 1, fp);

    printf("%d",123);
    printf("Header Size : %d\n Width : %d\n Height : %d\n Colorplanes %d\n Bits per Pixel: %d\n Compression:%d\n Image Size : %d\n",dibheader.header_size,dibheader.width,dibheader.height,dibheader.colorplanes,dibheader.bitsperpixel, dibheader.compression,dibheader.image_size);

    if ((dibheader.height != 40) || (dibheader.compression != 0 ) || (dibheader.bitsperpixel != 24)){fclose(fp); return 1 ;}

    // To go to the point where Image exists
    fseek(fp,header.image_offset,SEEK_SET);

    struct Image image = readImage(fp,dibheader.height,dibheader.width);

    imagetotext(image);
    createBWImage(header,dibheader,image);
    fclose(fp);
    freeImage(image);
    return 0;
}

int main(int argc , char * argv[]){
    if (argc !=2 ) {
        printf("Please Use Command: ./a.out filetoopen.bmp");
        return 1;
    }
    openbmpfile(argv[1]);
}

/*
Be careful about Padding done by C to make number of bytes as Multiple of 4.
*/