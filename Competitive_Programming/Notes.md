#### Misc. Important Points :

- Printing `2` as `2.00`  (Int as Float with known Precision) :-


```
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float m = 2;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << m;
}
```

```
// a= ++b
// This is pre-increment operation.
// The value of b will first be incremented and then used in the operation. Thus,

b = 3
a= ++b;
After execution b = 4; a = 4

// a = b++
// This is post-increment operation. First the value of b will be assigned to a and then incremented. Thus,

b = 3;
a = b++
After execution; a = 3; b = 4
```

```
int bar() { return x++; }


It's equivalent to:

int bar()
{
  int temp = x;
  ++x;
  return temp;
}

It returns before incrementing.


Similar thing holds for `cout << a++ << b--`
```

Pass by Reference as well as Pass by Pointer also can perform SWAPPING.

```

int main()
{
    double* val = NULL;
    val = new double;
    *val = 38184.26;
    cout << *val;
    delete val;
}
// Yields 38184.3
```

```
int main()
{
    extern int i;
    i = 20;
    cout << sizeof(i);
    return 0;
}

// Yields Error -> undefined reference to `i'
```

Structure Instance can have same name as structure 
Eg :-
```
struct sample
{
    int a;
} sample;

```


```
int main() 
{ 
    char str[] = "Cplusplus"; 
    cout << 5[str]; 
    return 0; 
}
// Yields `p`.
```

```
int main(){
    int *ptr = NULL;
    ptr++;
    delete ptr;
    return 0;
}

// Think about the Output.
```



Firstly these two represent the same.

`const int *` and `int const *`

- When using `const int*` or `int const *` - You are allowed to change the variable it points to, but can't dereference the pointer and change value.

- `int * const` - Works exactly the opposite way - You can dereference and change the value but can't change the variable it points to.

- `const int *` or `int const *` - pointer to const int - Can't dereference and update.

- `int * const` - const pointer to int - Can't change the variable it is pointing to.