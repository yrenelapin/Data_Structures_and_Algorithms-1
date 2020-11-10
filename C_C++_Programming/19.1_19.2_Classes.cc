#include <stdio.h>
#include<stdlib.h>

int count = 0;

class Student{

// Default permission is PRIVATE for all objects
private :
    char name[50];
    int age;
    unsigned int rollno;

 // Whatever lies below will be accessible.    
public :       

    // Constructor has same name as that of class. This is called everytime the OBJECT of class is created. 
    Student() {
        count++;
        printf("I am inside Constructor: %d\n",count);
        name[0] = 0;
        age = 0 ;
        rollno = 0;}

    // void init(){
    //     name[0] = 0;
    //     age = 0 ;
    //     rollno = 0;
    // }

// We can define the functions outside the class as well.
    
    void print();
  
    void scan(){
        printf("Enter Name:");
        scanf("%s",name);
        printf("Age:");
        scanf("%d",&age);
        printf("Enter Roll Number:");
        scanf("%d",&rollno);
    }

    ~Student();
};

// Telling the compiler that these functions belong to class Student.
void Student::print(){

    printf("\n Student Info \n Name:%s \n Age: %d \n Roll Number: %u",name,age,rollno);
}

// Everytime , we exit a class Instance, This is called 
Student::~Student() {    
        printf("\n Hi ! I am in the destructor..");
}


// We can even make all the Functions of the class outside the class and just keeping the names and typesin the class and then copy the entire Claa to header file.


int main(){

    class Student std;
    class Student std2;

   // std.init();  // Better way to do the samething is to use CONSTRUCTORS.
    
    std.scan();    // If we dont use this & directly called print() then it will print some random Values.
    std.print();
    std2.print();

}