#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"   // This is very Important 

/*
<name_of_header.h> Notation searches in the place where all the Libraries are present
To tell Compiler to search for the header in the same directory, We use "name_of_header.h" notation.

Since we had a Corresponding Header File for this image.cc file,
In this file We just have Function Definitions whose declarations are already present in image.h file.  
*/

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


int writeBMP(struct BMP* bmp, char* filename){

    int i ;
    FILE *fpw = fopen(filename,"w");
    if (fpw == NULL ) return 1;

    

    fwrite(bmp->header.name,2,1,fpw);
    fwrite(&(bmp->header.size), 3*sizeof(int),1,fpw);
    fwrite(&(bmp->dibheader),sizeof(struct DIB_header),1,fpw);

    for (i=bmp->image.height-1;i>=0;i--){ fwrite(bmp->image.rgb[i],((24* bmp->image.width + 31)/32)*4, 1 ,fpw);
    }

    fclose(fpw);
    return 0;

}



struct BMP* readBMP(char *filename){

    FILE *fp = fopen(filename,"rb");

    if (fp==NULL) return NULL;

    struct BMP* bmp ;

    bmp = (struct BMP*)malloc(sizeof(struct BMP));


    fread(bmp->header.name,2,1,fp);
    fread(&bmp->header.size, 3*sizeof(BITMAP_header),1,fp);

    printf("First two characters:%c%c \n",bmp->header.name[0],bmp->header.name[1]);

    if ((bmp->header.name[0] !='B') || ( bmp->header.name[1]!='M'))
    {fclose(fp); 
     free(bmp);
     return NULL ;
    }

    printf("Size of the file :%d \n",bmp->header.size);
    printf("Offset: %d\n",bmp->header.image_offset);
    printf("%d",123111);

    fread(&bmp->dibheader,sizeof(struct DIB_header), 1, fp);

    printf("%d",123);
    printf("Header Size : %d\n Width : %d\n Height : %d\n Colorplanes %d\n Bits per Pixel: %d\n Compression:%d\n Image Size : %d\n",bmp->dibheader.header_size,bmp->dibheader.width,bmp->dibheader.height,bmp->dibheader.colorplanes,bmp->dibheader.bitsperpixel, bmp->dibheader.compression,bmp->dibheader.image_size);

    if ((bmp->dibheader.height != 40) || (bmp->dibheader.compression != 0 ) || (bmp->dibheader.bitsperpixel != 24)){fclose(fp);
     free(bmp);
     return NULL;}

    fseek(fp,bmp->header.image_offset,SEEK_SET);

   bmp->image = readImage(fp,bmp->dibheader.height,bmp->dibheader.width);

    fclose(fp);
    return bmp;
}


/*
Be careful about Padding done by C to make number of bytes as Multiple of 4.
*/
  