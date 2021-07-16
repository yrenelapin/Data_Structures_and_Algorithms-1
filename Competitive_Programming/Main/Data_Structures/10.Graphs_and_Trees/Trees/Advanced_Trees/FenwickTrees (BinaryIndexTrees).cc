#include <bits/stdc++.h>
using namespace std;

// Considering array queries ( 1 <= L <= R <= n)
// FenwickTree[i] contains the sum of the values of range [  i - 2^r + 1,  i  ], where `i` is index ( 1 <= i <= n)
// and `r` represents the `position` ( 0 <=  position <= No_of_bits_in_i - 1 ) of the least significant bit of number `i` in Binary form.

int n = 100;

// Initialise tree with 0.
vector<int> FenwickTree(n+1);

// PrefixSum[i] -> O(logn)  //   1 <= i <= n
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += FenwickTree[i];
        // Get the next index to be added by flipping the rightmost bit, i.e we are removing the least significant bit.
        i -= i&-i;
    }
    return s;
}


// Add the `value` to array[i] -> O(logn)  //   1 <= i <= n
void update(int i, int value) {
    while (i <= n) {
        FenwickTree[i] += value;
        // Get the next index to be updated by flipping the leftmost bit, i.e we are adding the least significant bit.
        i += i&-i;
    }
}

// O(nlogn)
void build(vector<int> &arr){
    int n = arr.size();
    for (int  i = 1; i <= n; i++){
        update(i, arr[i-1] );
    }
}


int main(){
    // Notice that Input array is given as `0` indexed only since it was managed in build using arr[i-1].
    vector<int> arr = {5,8,6,3,2,7,2,6};
    int n = arr.size(); 

    build(arr);

    cout << sum(1) << endl ;
    cout << sum(3) << endl ;
    update(1,1);
    update(2,-2);
    cout << sum(1) << endl ;
    cout << sum(3) << endl ;

    // We can answer Range Sum queries as follows:
    // sum_q(a,b) = sum(b)−sum(a−1)

    // Sum of elements in range [1,3]
    cout << sum(3) - sum(0) << endl;

    // Sum of elements in range [2,5]
    cout << sum(5) - sum(1) << endl;

    // Sum of elements in range [3,4]
    cout << sum(4) - sum(2) << endl;
}