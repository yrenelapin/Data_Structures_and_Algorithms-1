#include <stdio.h>

class Vector{
private:
    int x;
    int y;

public:
    Vector();
    Vector(int c, int d); // Even for Constructors, we can do Overloading
    void set(int x1, int y1){x = x1 ; y = y1;}
    int squarenorm();
    void print(); 
    void print(int z); // Function Overloading (Type of Polymorphism)
    // Ploymorphism means Multiple Things having the Same Name
    
    Vector add(Vector v);

    // Operator Overloading
    Vector operator + (Vector v);
    int operator * (Vector v);
    
    Vector operator ++ ();

    void operator ++ (int);
};


// We can even Return Vectors if required
Vector Vector::operator ++(){
    x++;
    y++;
    Vector v(x,y);
    return v ;
}

void Vector::operator ++(int){
    x++;
    y++;
}


int Vector:: operator * (Vector v){
    return (x*v.x + y*v.y);
}

// Without Operator Overloading
Vector Vector::add(Vector v){
    Vector v2;
    v2.set(x+v.x, y+v.y);
    return v2;
}
// Operator Overloading
Vector Vector:: operator + (Vector v){
    Vector v2;
    v2.set(x+v.x, y+v.y);
    return v2;
}

int Vector::squarenorm(){
    return (x*x + y*y);
}

void Vector::print(int z){
    //Scale the vector by z.
    x = z*x;
    y = z*y;
    printf("\n(x,y) = (%d,%d)",x,y);
    
}

void Vector::print(){
    int nm = squarenorm();
    printf("\n(x,y) = (%d,%d)",x,y);
    printf("\nNorm = %d",nm);
}

Vector :: Vector ()
{
     x =0;y=0;
}


Vector :: Vector (int c , int d)
{
     x = c ; y=d;
}




int main(){

    // Vector *v = new Vector(); // new is a KEYWORD
    // Vector *v2 = new Vector(3,6);

    // // set is used for Memory Allocation. We need not specify size.
    // v->set(10,20);
    // v->print();
    // v-> print(2);

    // v2->print();

    // // Freeing the Memory using delete
    // delete v ;
    // delete v2;

    Vector u(3,5);
    Vector z(0,5);
    Vector v = u.add(z);
    v.print();

    // Using Operator Overloading
    Vector w = u + z;
    w.print();

    // Using Operator Overloading
    int y = u * z;
    printf("\n Dot product is %d",y);

    Vector t = ++u;
    u.print();
    t.print();
    
    z++;
    z.print();
 

}