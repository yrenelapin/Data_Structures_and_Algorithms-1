#include <bits/stdc++.h>
using namespace std;

// l denotes the left index
// r denotes the right index
// x denotes the element to be searched
// Returns the index of the x if it is present in v, else -1
int binary_search( vector<int> v, int l, int r, int x){

    // Notice the equality sign too.
    while ( l <= r ) {

        // This way of calculating helps in avoiding Overflow.
        int m = l + (r - l) / 2;
  
        // Check if x is present at mid
        if (v[m] == x)
            return m;
  
        // If x greater, ignore left half
        if (v[m] < x)
            l = m + 1;
  
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we could not find
    return -1;
}
 
  
int main() {    

    // We need a sorted data structure for binary search.
    vector<int> v =  {1,2,3,4,5,6,7,8,9,10};        

    int n = v.size();

    // Just testing the function.
    for(int i = 0; i <= 12; i++){

        // Notice that start index = 0, end index = n-1 and `i` element is being searched. 
        int res = binary_search(v, 0, n-1, i);

        if (res != -1 ){
            cout << i << " is present at " <<  res << "\n";}
        else{
            cout << i << " is not present in given vector \n";  
        }
    }

}   