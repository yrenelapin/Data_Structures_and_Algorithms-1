#### Misc. Important Points

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

Dont forget to consider the Integer OverFlow !!

```
#include <climits>

typedef long long ll;

ll left_sum = LLONG_MIN,

ll sum // It can hold very large Quantity
```

- `int mid = low + (high - low)/2;` This Helps in avoiding Overflow .
`typedef unsigned long long int ull;` This too..

- If required we can take Integer input as Strings.

- For `sort` We can pass the pointers too not only Iterators which Implies we can pass Array(Since It behaves like Pointer).

- Ternary Operators :

    `variable = (Expression) ? expressionTrue : expressionFalse;`

    Refer [this](https://media.geeksforgeeks.org/wp-content/uploads/20190920110229/Conditional-or-Ternary-Operator-__-in-C_C.jpg) for Clear Idea

- Let S1, S2 are Two Strings, `return S1.compare(S2) > 0 ? 1 : 0;`
  This returns 1 if Both strings are Equal or S1 > S2 Else It returns 0.
- This comes in handy If we want to compare Two Integers Lexicographically but not Numerically.
- `S1.compare(S2)` returns `Negative` Value if S1 < S2, `Positive` Value if S1 > S2. `Zero` If S1==S2.

- Let us assume `a` is of the type `string`. Then we can reverse a string in this way `reverse(a.begin(), a.end());`
- Be very careful while defining the  `custom comparator` function to use in `sort` function. If the Custom Function returns `true` Then the Order of parameters passed remains same & It gets swapped when it returns `false`. Solve the `Modulo Sort` question in the `Quick Sort` exam to get an Overview.
- Dont forget to use `push_back` function when Constructing an Vector from the Inputs.
  Ex :-

```
vector<int> a;
int n ;
cin >> n;
for(int i = 0; i< n; i++){
int temp;
cin >> temp;
a.push_back(temp);

}
```

- Checking for Disjoint elements in the 2 Vectors efficiently ( Holds for other containers too)

- find(START, END, KEY_TO_LOOK_FOR) returns an Iterator.

- Finds the element in the given range of numbers.
Returns an iterator to the first element in the range [first,last) that compares equal to val.
If no such element is found, the function returns last

-
Traversing elements of `a` and checking its presence in `b`.
  
```
  vector<int> a_uni;
  for (int i = 0; i < a.size(); i++ ){
  
    if ((!(find(b.begin(), b.end(), a[i]) != b.end())) 
        a_uni.push_back(a[i]);
  }
```

- Learning Algorithms Like Sorting Algos are helpful in similar scenarios like `Counting the Inversions/Divide and Conquer`
- Square in C++ is done by `pow(number, 2)`. We need to include `cmath`
- Getting the Unique Characters present in a given String :

```
    sort(s2.begin(), s2.end()); 
    auto res = unique(s2.begin(), s2.end()); 
    for (auto itr = s2.begin() ; itr != res; itr++){
        cout << *itr ;  // This prints the Unique characters in given string s2.
    }
```

- Finding the count of the characters in the string :
`int freq = count(s.begin(), s.end(), *itr);`  // Counting number of occurences of element at `itr` in the string `s`

Its always advisable to use `typedef long long int ll` or  `typedef unsigned long long int ull`in every question at every point except at `int main()`to avoid Overflow cases !!

We do the String to Integer and Viceversa Conversions as shown below :

- `int String2Integer =  stoi(StringName);`
- `string s = to_string(Number)`;

Sometimes TLE happens when we pass the arguments to functions as VALUES. Passing by Reference (Pointers) reduces the Time Complexity since it avoids Copying the entire data again

Counting Sort :

- We can use Counting Sort with Ordered_Map with any Input.But it will lead to O(nlogn)
- To use Counting Sort in Linear Time [ O(n+k) ] for Negative Input also, We make the Input numbers `Positive` by adding a `Fixed Number` before sorting & subtracting it after sorting.

### We can directly find out the Maximum Element using `max_element` under `algorithm` Header

`int max = *max_element(array, array + size)`

### To pass the Vector as an array or a Pointer, We can use this

```
vector<int> vec = { 10, 20, 30, 40, 50 };
int* pos = vec.data();
```

Generate random numbers between a negative and positive value :
The algorithm goes like this

```
min + rand() % ( max - min + 1 )
```

Checking whether a given number is Palindrome or not

```
#include <string>

bool pal(int i){
    string s = to_string(i);
    return ( s == string(s.rbegin(), s.rend()));
}
```

`rbegin()` -> Returns a reverse iterator pointing to the last element in the container.
`rend()` -> Returns a reverse iterator pointing to the theoretical element preceding the first element in the container
The range between `vector::rbegin` and `vector::rend` contains all the elements of the vector in REVERSE ORDER.

## Rotate the vector using STL

Types of Rotations :

`void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)`

first, last : Forward Iterators to the initial and final positions of the sequence to be rotated

middle : Forward Iterator pointing to the element within the range [first, last] that is moved to the **first position in the range.**

Left Rotation : To rotate left, we need to add the vector index. For example, you have to rotate vector left 3 times. The 3th index of vector becomes first element. `vec.begin() + 3` will rotate vector 3 times left.

Right Rotation : To rotate right, we need to subtract the vector index. For example, you have to rotate vector right 3 times. The 3th last index of vector becomes first element.`vec.begin()+vec.size()-3` will rotate vector 3 times right.

Example :

```
// Rotates/ Shifts the array to the right by `k` positions 
rotate(b.begin(), b.begin() + b.size()-k, b.end());   

// Rotates/ Shifts the array to the left by `k` positions 
rotate(b.begin(), b.begin() + k, b.end());   
```

When the Input is Unknown Number of  Space Separated Integers :-

```
vector<int> v;
int temp;
while (cin >> temp)
    { v.push_back(temp);}
```

When using the maps/sets, Better to use the find function present in the corresponding header only
Ex:

```

map <int,int> m;

m.find(data)->second   // This `find` comes from the corresponding `map` header only. This is better to use.

find(m.begin(), m.end(),data) // This `find` comes from the `algorithm` header. Avoid using this.
```

Also to check presence of element & incrementing ( Keeping track of Frequency ) use the code similar to below one :

```
    map <int,int> m;
    if ( m.count(data) == 0 ){
        m.insert(make_pair(data, 1));
    }
    else{
        // If the element is already present, Increment the count by 1.
        (m.find(data)->second)++;
    }
```

Also, To sort the map using its Values, We make use of extra Multimap & insert elements after swapping as shown below :

```


multimap<int, int, greater<int>> final_map;  // It contains descending order of elements based on keys

// Iterating over our initial map m which has pairs of (element, count)
    for (auto& it : m) { 
        
        // We make a map with pairs (count, element). Since it(final_map) is a
        // Multimap with gerater<int> specified, It sorts the elements based on 
        // the count in descending order

    final_map.insert({ it.second, it.first }); 
} 
    
```

Its better practise to free up Dynamically alloted memory after every test case, when dealing with Multiple Test Cases.

- In AVL Trees, During Rotation, We shift the SubTrees ! (Not just the Nodes)

- Though both AVL & Red-Black trees are balanced, when there are more insertions and deletions to make the tree balanced, AVL trees should have more rotations, it would be better to use red-black. but if more search is required AVL trees should be used.
  
- We can use `memset` to fill the memory or Initialise a container,
Ex :

```
    int array[n][n];
    memset(array, 0, sizeof(int)*n*n);
```

```
string str;
`scanf("%s", &str);` // Note that this wont work. C++ std::string wont work with SCANF.
cin >> str             // This should be used.
```

- Avoid Using `unsigned` unless required since it may introduce bugs that are hard to debug.
  
- Converting a `bitset` into Integer :

```

typedef long long int ll;
bitset<64> a;
...... 
int integer = (ll)a.to_ulong() 

```

- Searching a string for a character :

```
#include <iostream> 
#include <string> 
  
using namespace std; 
  
int main() 
{ 
    string str = "geeksforgeeks a computer science"; 
    string str1 = "geeks"; 

    // Find first occurrence of "geeks" 
    auto itr = str.find(str1); 
    if (itr != string::npos) 
        cout << "First occurrence is " << itr << endl; 

// IMPORTANT: If it is not found , `itr == string::npos`
```

- Use vectors for 2D Data Structures too Ex : For a 2D Rectangle of size m*n, instead of using int a[m][n], use :

```
// Filling the grid with m rows of vectors of size n;
vector<vector<int>> grid(m, vector<int>(n));

for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
        cin >> grid[i][j];
}


// So we can just pass the vector lonely to function & return.
// We can get dimensions in this way.
int m =  grid.size();
int n =  grid[0].size(); 
```

- Sometimes, Storing `strings` as `Vectors of characters` helps a lot to recursively iterate.
- Moreover, Sometimes, `Large numbers` are also stored as `Vectors of its each digits`.
- Use `#include <bits/stdc++.h>` to include all the header files.
  
- NOTE :
    In C++, all variables are declared with type. C++ forces you to specify the type explicitly, but doesn't force you to initialize the variable at all.

    ```
    long int a = 2;
    long int b = 2L;
    long int c; 
    ```

    This code above makes 3 variables of the same type long int.

    ```
    int a = 2;
    int b = 2L;
    int c;
    ```

    This code above makes 3 variables of the same type int.

    The idea of type is roughly "the set of all values the variable can take".
    It doesn't (and cannot) depend on the initial value of the variable - whether it's 2 or 2L or anything else.

    So, if you have two variables of different type but same value

    ```
    int a = 2L;
    long int b = 2;
    ```

    The difference between them is what they can do further in the code. For example:

    ```
    a += 2147483647; // most likely, overflow since Its of type `int`
    b += 2147483647; // probably calculates correctly
    ```

    The type of the variable won't change from the point it's defined onwards.

    Another example:

    `int x = 2.5;`
    Here the type of x is int, and it's initialized to 2. Even though the initializer has a different type, C++ regards the declaration type of x "more important".

    BTW C++ has support for "type inference"; you can use it if you want the type of the initializer to be important:

    ```
    auto a = 2L; // "a" has type "long int"
    auto b = 2; // "b" has type "int"
    ```

    ```
    typedef long long ll;
    ll K;
    if ((K %  2L ) == 0L) cout << "Bye" ;
    ```

    `L` is a long integer literal.
    Integer literals have a type of int by default; the L suffix gives it a type of long (Note that if the value cannot be represented by an int, then the literal will have a type of long even without the suffix).

- We can check whether a quantity is `infinity` or not using `isinf()`.
- We use `(int)` to type cast a ceiled float to get the number in the integer format instead of exponential powers.
Ex :-

```
float Final = 123123123.23123
cout << (int)ceil(Final);
```

- We need to send the same datatypes to min/max algos of STL. In such scenario's, `LL` at the back of integers may help
- Ex :

```
typedef long long int ll;
ll big = 100012;
cout << min (big, 12)   // Shows error
cout << min (big, 12LL) // Works fine

ll small = 12;
cout << min (small, big) // Anyhow works

```

- If we are sure that computation involves only positive values, Its advisable to use
`typedef unsigned long long int ulli` when dealing with large numbers. But sometimes it may yield unncessary erros if we include `unsigned` term

- If we knew the recurrence relations, Implementing using DP is very easy. Ex : Catalan Numbers, Fibonacci Sequence.
So, Knowledge of Maths helps a lot!!

- In most of the DP cases, We try to frame the subproblems in this way,
  1. Leave the last element/ Current element, reduce the number, solve
  2. Consider that last element/ Current element is included, reduce the number, modify accordingly, solve
  3. Combine the results of both the above 2 cases logically (Sometimes, It might be + , &&, etc...)
    Ex :
  - [Coin Change](https://www.geeksforgeeks.org/coin-change-dp-7/)
  - [Subset with Sum](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)
  4. Sometimes, DP problems becomes easy, if u know the base conditions since we can construct the equation from base terms.
  5. **In many cases of DP applications, Recursive Implementation is very Intuitive & Once we get the recursive implementation idea, we can easily translate it into the DP easily. So We can start thinking a DP problem's solution in a Recursive way including SUB PROBLEMS.**
  6. So Start with base cases, Think of a recursive approach, Draw a Recursive Tree, Convert it into Iterative Bottom Up appraoch using DP for more efficient solution.

    Ex : [Cutting a Rod](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/)

- Note the difference between the Subarray, subsequence, subset, substring

  ```
  Consider an array:

 {1,2,3,4}

Subarray: contiguous sequence in an array i.e.
{1,2},{1,2,3}

Subsequence: Need not to be contiguous, but maintains order i.e.
{1,2,4}

Subset: Same as subsequence except it has empty set i.e.
{1,3},{}

- A substring is exactly the same thing as a subarray but in the context of strings.

```

- Sometimes, Using `else` at the end of multiple `if` statements, leads to unexpected things.
- So Its better practise to use `else if` instead of multiple `if`. 

- We can deal with negative modulo with `abs` itself. Else we need to do `((a%k + k)%k)`