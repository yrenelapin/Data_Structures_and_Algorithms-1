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

GCD Properties :
- gcd{a,b} = gcd{|a|,b} = gcd{a,|b|} = gcd{|a|,|b|}  So, the result of gcd should always be printed as POSITIVE. 
- If a > b, GCD(a,b) = GCD(b, a%b)
- gcd(a,b,c) = gcd(a,gcd(b,c)) = gcd(gcd(a,b),c)                       // Associative
- gcd(a,b)=gcd(a,b−a) = gcd(a-b,b)                                     // Take abs for difference terms.
- GCD(x,y) = GCD(x−y,y). The same applies for multiple arguments: GCD(x,y,z,…) = GCD(x−y,y,z,…) . Note that we have to assume that GCD of an empty set is 0, and GCD(x,0)=x for any x, since 0 is the only number divisible by any other number. So start by initialising gcd to 0. [Example](https://codeforces.com/contest/1459/submission/119794117)
- Then we can extend to multiple arguments by mathematical induction :

    **gcd(a1,a2,⋯,an−2,an−1,an)** 

    =gcd(a1,a2,⋯,an−2,gcd(an−1,an))

    =gcd(a1,a2,⋯,an−2,gcd(an−1,an−an−1))

    =gcd(a1,a2,⋯,an−2,an−1,an−an−1)

    =gcd(a1,a2,⋯,gcd(an−2,an−1),an−an−1)

    =gcd(a1,a2,⋯,gcd(an−2,an−1−an−2),an−an−1)

    =gcd(a1,a2,⋯,an−2,an−1−an−2,an−an−1)

    ⋯

    =gcd(a1,a2−a1,⋯,an−1−an−2,an−an−1)

    We do not need to choose adjacent differences. gcd(a1,a2,⋯,an−2,an−1,an) is also equal to gcd(a1,a2−a1,⋯,an−1−a1,an−a1), which can be proved similarly.


