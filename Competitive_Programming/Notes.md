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
- ` S1.compare(S2)` returns `Negative` Value if S1 < S2, `Positive` Value if S1 > S2. `Zero` If S1==S2.

- Let us assume `a` is of the type `string`. Then we can reverse a string in this way `reverse(a.begin(), a.end());`
-  Be very careful while defining the  `custom comparator` function to use in `sort` function. If the Custom Function returns `true` Then the Order of parameters passed remains same & It gets swapped when it returns `false`. Solve the `Modulo Sort` question in the `Quick Sort` exam to get an Overview.
-  Dont forget to use `push_back` function when Constructing an Vector from the Inputs.
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
-  Square in C++ is done by `pow(number, 2)`. We need to include `cmath`
-  Getting the Unique Characters present in a given String :
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
- ` string s = to_string(Number)`;

Sometimes TLE happens when we pass the arguments to functions as VALUES. Passing by Reference (Pointers) reduces the Time Complexity since it avoids Copying the entire data again


Counting Sort :
- We can use Counting Sort with Ordered_Map with any Input.But it will lead to O(nlogn)
- To use Counting Sort in Linear Time [ O(n+k) ] for Negative Input also, We make the Input numbers `Positive` by adding a `Fixed Number` before sorting & subtracting it after sorting.

### We can directly find out the Maximum Element using `max_element` under `algorithm` Header
`int max = *max_element(array, array + size)`

### To pass the Vector as an array or a Pointer, We can use this :
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
 
-  Though both AVL & Red-Black trees are balanced, when there are more insertions and deletions to make the tree balanced, AVL trees should have more rotations, it would be better to use red-black. but if more search is required AVL trees should be used.
  
-  We can use `memset` to fill the memory or Initialise a container,
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
- 