/*
Author : Sanjay Marreddi
Date   : 10th November,2020.

This header file will make the image Package which helps i dealing with BMP Files.

It is a best practise to have the details of the Author, Time and Main Idea of header file in its beginning as shown above.
*/

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

struct BMP {

    struct BITMAP_header header;
    struct DIB_header dibheader;
    struct Image image;

};

/* 
 Declaring the Functions whose definitions are present in image.cc file.
*/
struct Image readImage(FILE *fp, int height, int width);
void freeImage(struct Image pic);
unsigned char grayscale(struct RGB rgb);
void RGBImageToGrayscale(struct Image pic);
void imagetotext(struct Image img);
int writeBMP(struct BMP* bmp, char* filename);
struct BMP* readBMP(char *filename);