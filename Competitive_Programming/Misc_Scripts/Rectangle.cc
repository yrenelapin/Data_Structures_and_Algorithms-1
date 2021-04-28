/*
Author : Sanjay Marreddi
Roll No : 1904119
Date: 11th November 2020             

This file contains code for a Class Rectangle which satisfies the given conditions.
*/

#include <stdio.h>
#include <stdlib.h>

class Rectangle{
private:
    
    // (x1,y1) represents bottom-left most point and (x2,y2) represents the top-right most point

    int x1,y1,x2,y2; 
public:

    Rectangle();
    void set (int a, int b, int c, int d);
    int area();
    bool operator < (Rectangle r);

};

Rectangle::Rectangle(){
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

/*
Returns the area of the rectangle 
*/
int Rectangle::area(){
    int Area = (x2-x1)*(y2-y1);
    return (Area);    
}

/*
Overloads the Less than Operator for comparing two Areas.
*/
bool Rectangle::operator < (Rectangle r){
        int Area_1 = area();
        int Area_2 = r.area();
        return ( Area_1< Area_2);
}

void Rectangle::set(int a, int b, int c, int d){
    x1 = a; 
    y1 = b;
    x2 = c;
    y2 = d;
}

int main(){
    Rectangle R1 ;
    R1.set(1,2,3,4);
    int result_area = R1.area();
    printf("\nThe Area of the Rectangle R1 is %d",result_area);

    Rectangle R2 ;
    R2.set(1,3,5,7);

    // Here we are comparing Two Rectangles with Less tha Operator i.e. Operator Overloading
    bool comparison = R1<R2;
    
    if (comparison){
        printf ("\nThe Area of Rectangle R1 is Less than Area of the Rectangle R2");}
    else 
        printf ("\nThe Area of Rectangle R1 is not Less than Area of the Rectangle R2");
}