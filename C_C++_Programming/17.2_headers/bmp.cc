#include <stdio.h>
#include <stdlib.h>

#include "image.h"

int main(int argc , char * argv[]){
    if (argc < 2 ) {
        printf("Please Use Command: ./a.out input.bmp output.bmp");
        return 1;
    }
    struct BMP* bmp = readBMP (argv[1]);

    imagetotext(bmp->image);

    RGBImageToGrayscale(bmp->image);

    if (argc > 2) writeBMP(bmp, argv[2]);
  
    freeImage(bmp->image);

    free(bmp);

  
}

/*
STEPS TO RUN  THE PACKAGE (image):- 

`gcc -c image.cc` just makes it Compile
`ls im*` to see the Output file
`gcc bmp.cc image.o`
`./a.out pic.bmp`


Put image.o in to the Library folder and then image.h in the headers folder. Put the image header in your code and use it.

From now always use this Package Mode for solving !!
*/

