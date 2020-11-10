```
#include <stdio.h>

int main()
{
    int i = 1, 2, 3;
    
    printf("%d", i);
    
    /*COMPLIER ERROR
    Comma acts as a separator here. The compiler creates an integer variable and initializes it with 1. The compiler fails to create integer variable 2 because 2 is not a valid identifier.*/

    return 0;
}
```
```
#include <stdio.h>

int main()
{
    int i = (1, 2, 3);
    
    printf("%d", i);
    /*
    Prints 3
    The bracket operator has higher precedence than assignment operator. The expression within bracket operator is evaluated from left to right but it is always the result of the last expression which gets assigned. 
    
    */
    
    return 0;
}
```

```
#include <stdio.h>

int main()
{
    int i;
    
    i = 1, 2, 3;
    printf("%d", i);
    /*
    Prints 1
    Comma acts as an operator. The assignment operator has higher precedence than comma operator. So, the expression is considered as (i = 1), 2, 3 and 1 gets assigned to variable i.
    */
    
    return 0;
}
```

- Encapsulation allows us to focus on what something does without considering the complexities of how it works.
- Abstraction allows us to consider complex ideas while ignoring irrelevant detail that would confuse us.
- A publicly derived class is a subtype of its base class.
- Inheritance provides for code reuse.
- Overloading is a static or compile time binding and overriding is dynamic or runtime binding.
- Converting a primitive type data into its corresponding wrapper class object instance is called Autoboxing.
- Instantiation is creation or a real instance or a particular realization of an abstraction or template.
- Wrapping encapsulates and hides the underlying complexity of another entity.
- Boxing is the process of converting a value type to the type object or to any interface type implemented by this value type
- Members of a class are `private` by default and members of struct are `public` by default. When deriving a struct from a class/struct, default access-specifier for a base class/struct is public and when deriving a class, default access specifier is private.
- Size of an empty class is not zero in C++
- Objects of a class do not share non-static members. Every object has its own copy.
- Header file can not be passed to a function in C++.
- Every class containing abstract method must be declared abstract.
- Abstract class can not be directly be initiated with ‘new’ operator.
- Abstract class can be initiated.
- Abstract class does not contain any definition of implementation.
- When a method in a subclass has the same name and type signatures as a method in the superclass, then the method in the subclass overrides the method in the superclass.
- Overloading allows different methods to have same name, but different signatures where signature can differ by number of input parameters or type of input parameters or both. Overloading is related to compile time (or static) polymorphism..
- Friend Class A friend class can access private and protected members of other class in which it is declared as friend.
- The capability of a class to derive properties and characteristics from another class is called Inheritance.
- When one object reference variable is assigned to another object reference variable then a copy of the reference is created