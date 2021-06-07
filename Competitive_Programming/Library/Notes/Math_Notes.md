-  GCD(i, i+1) = 1 for all i>= 1
-  Catalan numbers satisfy the following recurrence relation :
    ![image info](https://www.geeksforgeeks.org/wp-content/ql-cache/quicklatex.com-6e37684751c57a980ebaca5148b4736a_l3.svg)
- There are lots of applciations of [Catalan Numbers](https://www.geeksforgeeks.org/applications-of-catalan-numbers/)

- Fibonacci Numbers are : F0 = 0, F1 = 1, Fn = Fn-1 + Fn-2.  Note that these sequences may occur in general problems too.

Check if Integer (X) can be written as a summation of Integral Multiple of two numbers.
Ex : X, 11, 111

```
X = a*11 + b*111    // a, b are Integers
``` 
- Trick is to express coefficient of bigger number in terms of smaller number so that we can BRUTEFORCE easily.

```
b = c*11 + d,  Here   0 <= d < 11   // c, d are Integers

X = a*11 + ( c*11 + d )*111

X = 11*( a + c* 111 ) + d*111
```
Now we can bruteforce as follows. For each value of d, subtract d*111 from X & check if the result % 11 == 0.

- Sum-Xor property: `(a+b) = ( a⊕b + 2(a&b) )`. Extended Version with two equations: `(a+b) = ( a|b + a&b AND a⊕b ) = (a|b − a&b).` [Example.](https://codeforces.com/problemset/problem/1325/D)

- The pigeonhole principle states that if `n` items are put into `m` containers, with `n>m`, then at least one container must contain more than one item.