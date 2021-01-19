#include <stdio.h>
#include <stdlib.h>

struct Address
{
    int houseno;
    char streetname[50];
    char country[50];
};


struct Student
{
    char name[50];
    int age;
    float marks;
    int numOfAddress;

    // Student have multiple addresses. So better to allocate Memory Dynamically.
    struct Address *address ;
    
};


int writeToFile(struct Student student){

        int i ;
        FILE* fp = fopen("student.txt","w");

        if (fp==NULL) return 1;

        fprintf(fp,"%s %d %f %d \n", student.name,student.age,student.marks,student.numOfAddress);

        for(i=0;i<student.numOfAddress;i++){
            fprintf(fp,"%d %s %s\n",student.address[i].houseno,student.address[i].streetname,student.address[i].country);

        }

        fclose(fp);
        return 0 ;
}


/*
Reading a Structure from a File

Since we dont know the amount of data present initially in the File, Its advisable to use Pointers
*/

struct Student* readFromFile(){

    int i ;

    struct Student *student = (struct Student* ) calloc(1,sizeof(struct Student));

    FILE* fp = fopen("student.txt","r");

    if (fp==NULL) return NULL;

    // Note that Delimeter is Important...If New Line%[^\n] 

     // When accessing from Pointer We use ->

    fscanf(fp,"%s %d %f %d",student->name, &student->age,&student->marks,&student->numOfAddress);

    student->address = (struct Address*) calloc (student->numOfAddress,sizeof(struct Address));

    for(i=0;i<student->numOfAddress;i++){
        fscanf(fp,"%d %s %s",&student->address[i].houseno,
        student->address[i].streetname,
        student->address[i].country);}

    fclose(fp);
    return student;
}


/* 
Defining a Function that returns a "struct Student" Type.
*/
struct Student readStudentInfo(){
    struct Student student ;
    int num = 0,i;

    printf("\nEnter your name:");
    scanf("%[^\n]",student.name);
    printf("\nEnter age:");
    scanf("%d",&student.age);
    printf("\n Enter your Marks:");
    scanf("%f", &student.marks);

    printf("\n Number of addresses:");
    scanf("%d",&num);
    student.numOfAddress = num;

    // Allocating Dynamic Memory for Address
    student.address = (struct Address*) malloc(num*sizeof(struct Address));

    for (i=0;i<num;i++){
        printf("\nHouse number (for address %d)", i+1);
        scanf("%d", &student.address[i].houseno);

        printf("\nStreet name (for address %d)",i+1);
        scanf("%s",student.address[i].streetname);

        printf("\nCountry (for address %d)", i+1);
        scanf("%s",student.address[i].country);
    }

    return student;
}

void printStudentInfo(struct Student student){

    int i ;
    
    printf("\nStudent Info \n Name: %s\n Age :%d\n Marks : %f \n",student.name,student.age,student.marks);

    for(i=0;i<student.numOfAddress;i++){
        printf("\nAddress(%d)\nHouse number:%d\n Street Name:%s\n Country :%s\n",i+1,student.address[i].houseno,student.address[i].streetname,student.address[i].country);

    }

}

/*
We will clear the Dynamically alloted memory.
*/
void clearMemory(struct Student student){
    free (student.address);
}



int main(){

    struct Student student = readStudentInfo();
    printStudentInfo(student);
    writeToFile(student);
    clearMemory(student);

    struct Student *std = readFromFile();
    printStudentInfo(*std);
    clearMemory(*std);      // "std" is a Pointer  "*std" is a Student Data Type 
    free(std);              

}

/*
Note:
1) Be Careful when reading from file .Take Care about Delimeter.
2)Free Up Space Accordingly.
*/