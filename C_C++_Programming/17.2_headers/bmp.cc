/*
In this file, We are testing our image Package (image.cc, image.h)
*/

#include <stdio.h>
#include <stdlib.h>

#include "image.h"   // This is very Important 

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

NOTE :

When ever we are dealing with Header files in Cpp in VS CODE & g++ Compiler, We may encounter :-

`Undefined reference`  means that whilst the compiler understands how the function should work 
(which means it understands the name of the function, the input types and the return type), the linker cannot find the actual
compiled code that actually does the work.

So, it's always advisable to compile in this way `g++ main.cc header_file.cc`

Here : In this Example : - `g++ bmp.cc image.cc` 
This will create `a.exe`. Now run this Executable.



STEPS TO RUN  THE PACKAGE (image):- 

`gcc -c image.cc` just makes it Compile
`ls im*` to see the Output file
`gcc bmp.cc image.o`
`a.exe pic.bmp`

To use custom Package like Inbuilt ones :-
Put image.o in to the Library folder and then image.h in the headers folder. Put the image header in your code and use it.
*/

