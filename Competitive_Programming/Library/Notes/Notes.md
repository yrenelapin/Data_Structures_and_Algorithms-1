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

  Consider an array: {1,2,3,4}

    Subarray: contiguous sequence in an array i.e.
    {1,2},{1,2,3}

    Subsequence: Need not to be contiguous, but maintains order i.e.
    {1,2,4}

    Subset: Same as subsequence except it has empty set i.e.
    {1,3},{}

    A substring is exactly the same thing as a subarray but in the context of strings.


- Sometimes, Using `else` at the end of multiple `if` statements, leads to unexpected things.
- So Its better practise to use `else if` instead of multiple `if`. 

- We can deal with negative modulo with `abs` itself. Else we need to do `((a%k + k)%k)`

- Better to use `sqrt()` for getting square roots instead of `pow(10, 1/2)`.
- The maximum precision can be set using the below code. 
      ```
      cout.precision(17);
      cout  << fixed ;
      ```
-  Maximum float we can use in C++ is `long double`
-  To find the occurence of a First occurence of a substring in a string from the end (i.e. Last Occurence of a substring in a string), We use `str.rfind("substr")`

- Dont use `typedef long long int ll` unless required. When dealing with the STL Library functions, Storing the results in
  `ll` format leads to unexpected results. 
  Ex:
  ```
       int occ_11 = s.find("11");    // This Works

       // ll occ_11 = s.find("11");  // This wont work as expected.

       if (occ_11 != -1){
           cout << "found";
       }
  ```
- `size_t` is an unsigned integer data type which can assign only 0 and greater than 0 integer values. 
  It measures bytes of any object's size and returned by sizeof operator. const is the syntax representation of `size_t`, but without const you can run the program. `const size_t number;`
- Dont forget changing the `INT_MAX` to `ULLONG_MAX` when dealing with `unsigned long long` type.
- Say we want to take TIME as input. We can read it as STRING entirely using cin  & take required quantities or Using scanf & pattern, take only require quantities.
        Ex :-
```
        // INPUT : 12:30

        // Method-1
        int h, m, curr_h_int,curr_m_int;
        scanf("%d%d%d:%d", &h, &m, &curr_h_int, &curr_m_int);


        // Method-2
        int h, m;
        string s;
        cin >> h >> m >> s;
        int curr_h_int = stoi(s.substr(0, 2));
        int curr_m_int = stoi(s.substr(3, 2));
```
- Note that we cant use both methods in a same program at different locations if we used the line 
        ` ios_base::sync_with_stdio(0); cin.tie(0);`. Since we turned off sync between cin  & scanf.
- Note that, Character array & string datatype are not exactly SAME.
- Tokenizing a `string` dataype based on a delimeter :- 
  ```
    // Tokenizing a String based on ":"

    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    string input = "abc:def:ghi";
        stringstream ss(input);
        string token;

        while(getline(ss, token, ':')) {
            cout << token << '\n';
        }
    }
  ```
- Minimum number to be added to x to make it divisible by k.
```
int min_number_to_be_added(int x, int k) {
    return ( k - (x % k) ) % k;}
```
- **Fact:** A point with the smallest summary distance is between left and right median. 
    The summary distance is the sum of distances from the point to all the other points on the Line. 
    To find out No of such points on NUMBER LINE of Integers with minimal summary distance, We only need to sort the array and find the elements on positions ⌊(n+1)/2⌋ and ⌊(n+2)/2⌋ and return their difference plus one.
    ```
    Ex :
    Input Points :  0,2,3,1 
    Sorted : 0,1,2,3 
    n = 4
    Left median (2nd element)  is 1, Right Median (3rd element) is 2. No of elements =  (2-1) + 1 = 2.
    Therefore 2 such points with Minimal Summary distance exist for the given input points.
    
    // ACTUAL IMPLEMENTATION
        
    ll count(ll arr[]){
        sort(arr, arr+n);
        ll right_median  =  (n) / 2  ;
        ll left_median   =  (n - 1) / 2   ;
        return ( arr[right_median] - arr[left_median] ) + 1 ;
    }    
    ```

- Don't make the vectors/any sort of containers as Global Variables. If we make it, We need to ensure that they are cleared after each test case. So, Keep them inside the loop of test cases only so that we need not clear them.

- Dont make silly mistakes in Binary search. Depending upon the Problem, The way we update the `low` and `high` limits accordingly with `mid` term in each iteration differs.
  
  Ex :-
  ```
  // In Binary search :

    int main() {
    
    fastIO;
    ll arr[] =  {1,2,3,4,5,6,7,8,9,10};        
    ll x = 8;
    
    ll low = 0;
    ll high = sizeof(arr)/sizeof(arr[0]) -1;
    ll mid ;
    while (high > low){
        
        mid = (high + low)/2;                         // Till this line, Everything will be same for every implementation.

        if ( arr[mid] > x )  {
            high = mid;                               // Notice this
        }
        else if  ( arr[mid] < x ) {
            low = mid;                               // Notice this
        }   
        else{
            break;
        }
    }

    if (arr[mid] == x) {
        cout << "found";
    }
    // deb(arr[mid]); deb2(arr[low], arr[high]);
    }   
  ```
    Now Lets take a problem that involves Binary search :
    Ex :- https://codeforces.com/contest/1490/problem/E
    
    ```
    bool Can_Win(ll position, vector<ll> &sorted_input){
        
        ll curr_tokens = sorted_input[position];
        for (ll i = 0 ;  i<sorted_input.size() ; i++){
            
            if (i == position){
                continue;
            }
    
            if ( curr_tokens < sorted_input[i]){
                return false;
            }
    
            curr_tokens += sorted_input[i];
        }
    
        return true;
    
    }
    
    int main() {
        
        fastIO;
        ll t, n, temp;
        cin >> t;
        while (t--) {
 
            vector<ll> input;
            vector<ll> sorted_input;
            
            cin >> n;
            for (ll  i = 0; i <n; i++){
                cin >> temp;
                input.push_back(temp);
                sorted_input.push_back(temp);
            }
    
            sort(all(sorted_input));
    
            ll low = 0;
            ll high = n-1;
            ll mid;
            while (high > low){
                
                mid = (high + low)/2;                       // Till this line, Everything will be same for every implementation.
    
                if (Can_Win(mid, sorted_input)){
                    high = mid;                             // Notice this
                }
                else{
                    low = mid+1;                           // Notice this. If we put, `low = mid` It never converges.
                }
            }
            
            vector<ll> result;
            for (ll i = 0; i <n ; i++){
                if (input[i] >= sorted_input[high]){
                    result.push_back(i+1);
                }
            }
    
            cout << result.size() << endl;
            for (ll i = 0; i< result.size() ; i++){
                cout << result[i] << " ";
            }
    
            cout << endl;
    
        }
    
        return 0;
    }

    ```
## upper_bound & lower_bound

- `upper_bound` :

- Returns an iterator pointing to the first element in the range [first,last) `which compares greater than val.`
- There are 2 versions. The elements are compared using operator< for the first version, and comp for the second. 
- **The elements in the range shall already be sorted according to this same criterion (operator< or comp), or at least partitioned with respect to val.**
- Unlike lower_bound, the value pointed by the iterator returned by this function cannot be equivalent to val, only greater.
#### Searches for the first value which is greater than val given.  

- In order to find the Maximum element in a sorted vector (or any sorted container) which is less than  or equal to a given Value, `val`
  We can use `upper_bound`.
  i.e I want to find a value which is maximum among all the values that are less than or equal to 15 in vector v = {1,13,14,14,15,16,17,18};

```
  auto itr = upper_bound(v.begin(), v.end(), 15);
  itr--;
  int required_number = *itr;
````
 

- `lower_bound` : Returns an iterator pointing to the first element in the range [first,last) which `does not compare less than val.`
- There are 2 versions. The elements are compared using operator< for the first version, and comp for the second. 
- **The elements in the range shall already be sorted according to this same criterion (operator< or comp), or at least partitioned with respect to val.**
- Unlike upper_bound, the value pointed by the iterator returned by this function may also be equivalent to val, and not only greater.
#### Searches for the first value which is greater than or equal to val given.

```

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}

Result : 
lower_bound at position 3
upper_bound at position 6

```

- For multisets,  `auto itr =  s.upper_bound(val);` is faster than `auto itr =  upper_bound(s.begin(), s.end(), val);`

- In questions, Where we are using DP & we are supposed to make Matrices/Tables, Make them as Global Variables with the Maximum Size required based on the Constarints mentioned in the Problem Statement. Example for Reference [here](https://codeforces.com/contest/1498/submission/111851989

## Removing elements from Vector

```
vector<int> v = {1,2,3,4,5};

// Removes all the elements of the vector & makes it size 0.
v.clear();   


// To remove the elements of the vector using position, we use erase.

v.erase(itr);                   // Removes the single element at given position, itr.
v.erase(start_itr, end_itr);    // Removes a range of elements ([start_itr, end_itr))

```
IMPORTANT : Remove an element from the vector using an element.
- std::remove : It doesn’t actually delete elements from the container but only shunts non-deleted elements forwards on top of deleted elements.
- std::remove does not actually erase the element from the container, but it does return the new end iterator which can be passed to container_type::erase to do the REAL  removal of the extra elements that are now at the end of the container.

For this task, we use the [erase-remove](https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom) idiom.
```
bool IsOdd(int i) { return i & 1; }

void Print(const std::vector<int>& vec) {
  for (const auto& i : vec) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main() {
    // Initializes a vector that holds numbers from 0-9.
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Print(v);

    // Removes all elements with the value 5.
    v.erase(std::remove(v.begin(), v.end(), 5), v.end());
    Print(v);

    // Removes all odd numbers.
    v.erase(std::remove_if(v.begin(), v.end(), IsOdd), v.end());
    Print(v);
}

/*
Output:
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 6 7 8 9
0 2 4 6 8
*/
```
- If we need `⌈m/a⌉` i.e Ceil of m/a, Performing `ceil(m/a)` will yield wrong value, since C++ rounds the value inside itself after performing divisio. So we need to use `ceil(m/(float)a)` or **the other option is to use `( ( m + (a-1) ) /a)` to get the value of Ceil of m/a.**

- Whenever TLE occurs, First think in terms of DP, Think whether same SUB PROBLEM is being repeatedly called or not.
Then if DP is suitable, First pre calculate using the maximum values provided in the question.

- In Questions, where answer%MOD is asked, **Dont use** `unsigned`.
Instead, simply use, `#define ll long long` and take Mod at every step in the solution, where the numbers can overflow.
Whenever there is a chance of overflowing, using the `ll` at every position instead of `int` creates no ERRORS. It helps.
  
- In C++
    - We cant modify the element of a set, We can just remove or insert elements.
    - We cant modify the existing `key` of a map i.e, we cant change the first element in the pair, We can just remove or insert keys. 
    - We can modify the `value` of the existing `key`, eg: mymap['key']++;

- `Deques` are faster for insertion/deletion of elements at the beginning than `vectors`.
- Using Builtin functions from GCC also helps in Bit Manipulations. Refer this [link](https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/)
- When dealing with multiplications/additions of numbers using `ll` be very careful & declare the `type` of the temporary values too. Also when using the `pow` to raise power of numbers. 

- Use `size()`
 ```
  vl a = {1,2,3,4,4};
  ll n = sizeof(a) / sizeof(a[0])     // This way of computing vector size when dealing with vector of LONG LONG yields incorrect value.
  ll n = a.size();                    // Works
```
- All Interactive Problems need not use BINARY/TERNARY SEARCH approach. They can be Constructive in nature too. Example [here](https://codeforces.com/contest/1521/problem/C)

- Sometimes, using Normal arrays is better than using complicated containers like multimap,etc. [Ex](https://codeforces.com/contest/1515/submission/116906408)
-  With the current template, we have a bug here :

```
  vll results;
  // `results` store the subsets of a given vector.


  fr(i,0,results.size()-1){
      ll size = ( results[i].size()-1 );  
      fr(j, 0, size){                                     // This works. but  `fr(j, 0,  results[i].size()-1 ){  }` wont work.
          cout << results[i][j] << " ";                   // becoz, the template just expects direct value. It cant do the computation (+,-..) there. 
      }
      cout << endl;
  }
```

DP Notes :
- In Recursive Memoisation, Usually we will have conditions for validation ( like out of possible Indices) which need not be included in the DP/Lookup table. We just need to return some values like 0/1/INT_MAX/INT_MIN/something depending on the context.
- So structure/order of Recursive Memoisation looks somewhat like :
   VALIDATION -> LOOKUP -> BASE CASE -> RECURSIVE STEP -> STORE in LOOKUP & RETURN.
- In CF Contests, Recursive always works. But sometimes may be difficult to think. Some times on GFG/LEETCODE/Interview Bit, It may yield TLE. So, 1st try for RECURSIVE always, If it fails or gives TLE/Memory exceeded go for ITERATIVE. Its anyhow very easy to convert Recursive to Iterative. Just need to think which subproblem to be solved first. ( TOPOLOGICAL SORTING. )

- If we are sure that, all the quantities are positive & they are very large, we can use , `unsigned long long` instead of `long long`
- If we declare Vector with Initialisation in Global & take size of vector from INPUT in the Local Function, It gives unexpected errors since `n` gets random value in the beginning & the corresponding sized vector may be created.
   ```
   ll n;
   vl dp(n+1,-1);


   void solve(){
       cin >> n ;;
       ....
   }
    ```
- Note that `Segmentation fault (core dumped)` error may arise even when u exceeded the Memory provided, i.e. Stack overflow due to many recursive calls. Read more cases [here](https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/)

- Keeping track of the Current Max element in STACK : 
An efficient approach would be to maintain an auxiliary stack while pushing element in the main stack. This auxiliary stack will keep track of the maximum element.

    Steps :
    1. Create an auxiliary stack, say ‘trackStack’ to keep the track of maximum element
    2. Push the first element to both mainStack and the trackStack.
    3. Now from the second element, push the element to the main stack. Compare the element with the top element of the track stack, if the current element is greater than the top of trackStack then push the current element to trackStack otherwise push the top element of trackStack again into it.
    4. If we pop an element from the main stack, then pop an element from the trackStack as well.
    5. Now to compute the maximum of the main stack at any point, we can simply print the top element of Track stack.

```
class StackWithMax
{
    // main stack
    stack<ll> mainStack;
  
    // stack to keep track of max element
    stack<ll> trackStack;
  
public:
    void push(ll x)
    {
        mainStack.push(x);
        if (mainStack.size() == 1)
        {
            trackStack.push(x);
            return;
        }
  
        if (x > trackStack.top())
            trackStack.push(x);
        else
            trackStack.push(trackStack.top());
    }
  
    ll getMax()
    {
        return trackStack.top();
    }
  
    ll pop()
    {
        mainStack.pop();
        trackStack.pop();
        return 0;
    }

    ll empty()
    {
        return mainStack.empty();
    }

    ll top()
    {   ll ele = mainStack.top();
        return ele;
    }
};

// Using in Code :
StackWithMax s;
s.push(1);
s.getMax();

Note that only functions defined above can be used with the class. All builtins are not possible (obviously).
```

Time Complexity : O(1)

Auxiliary Complexity : O(n)

Reference : [Link](https://www.geeksforgeeks.org/tracking-current-maximum-element-in-a-stack/)

- Checking whether a given string of brackets is a regular bracket sequence or not :
- A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example, bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)" whereas ")(", "((()" and ")" are not.

```
// From GFG
bool isBalanced(string exp)
{
    // Initialising Variables
    bool flag = true;
    int count = 0;
  
    // Traversing the Expression
    for (int i = 0; i < exp.size(); i++) {
  
        if (exp[i] == '(') {
            count++;
        }
        else {
            // It is a closing parenthesis
            count--;
        }
        if (count < 0) {
            // This means there are
            // more Closing parenthesis
            // than opening ones
            flag = false;
            break;
        }
    }
  
    // If count is not zero,
    // It means there are more
    // opening parenthesis
    if (count != 0) {
        flag = false;
    }
  
    return flag;
}
```
