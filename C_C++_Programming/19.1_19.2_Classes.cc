#include <stdio.h>
#include<stdlib.h>

int count = 0;

class Student{

// Default permission is PRIVATE for all members of the Class

private :
    char name[50];
    int age;
    unsigned int rollno;

// Whatever elements lie below the keyword "public" will only be accessible outside the class.    

public :       
    /*
    Constructor has same name as that of class. This is called everytime an OBJECT of class is created.
    We use the Constructors for Initialising the variables. It has no return type specified. 
    */
    Student() {
        count++;
        printf("I am inside Constructor: %d\n",count);
        name[0] = 0;
        age = 0 ;
        rollno = 0;}

    // We can define the functions of a Class, outside the class as well.
    void print();
  
    void scan(){
        printf("Enter Name:");
        scanf("%s",name);
        printf("Age:");
        scanf("%d",&age);
        printf("Enter Roll Number:");
        scanf("%d",&rollno);
    }

    // This is a Destructor for this class.Everytime , we exit a class Instance, This is called. 
    ~Student();
};

// Telling the compiler that these functions belong to class Student using :: Notation.
void Student::print(){
    printf("\n Student Info \n Name:%s \n Age: %d \n Roll Number: %u",name,age,rollno);
}
// Defining the Destructor outside the Class.
Student::~Student() {    
        printf("\n Hi ! I am in the destructor..");
}


/* 
We can even make all the Functions of the class outside the class and 
just keeping the names and types in the class and then copy the entire Class to header file.
*/

int main(){

    class Student std;
    class Student std2;
    
    std.scan();    
    std.print();
    std2.print();

}