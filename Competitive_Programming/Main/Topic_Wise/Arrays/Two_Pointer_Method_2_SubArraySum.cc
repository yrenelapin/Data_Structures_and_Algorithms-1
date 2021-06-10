#include <bits/stdc++.h>
using namespace std;

/*
we are given an array of n positive integers and a target sum x, and
we want to find a subarray whose sum is x or report that there is no such subarray.
*/

// O(N)
pair<int,int> two_pointer(vector<int> &v, int x){

    int start = 0;
    int end = 0; int curr_sum = 0;
    while (start <= end ){ // They should not be equal since we need a pair of elements.
         
        curr_sum += v[end];

        if (curr_sum == x) {
            pair<int,int> res(start, end);
            return res;
        }

        if (curr_sum < x){
            end++;
        }

        else{
            curr_sum -= v[end];
            curr_sum -= v[start];
            start++;
        }

    }
    pair<int,int> res(-2,-2); // No pair found
    return res;

}

int main(){
    vector<int> v = {1, 3, 2, 5, 1, 1, 2, 3};
    int x = 8;
    auto res = two_pointer(v,x);
    // Indices found
    cout << res.first << " " << res.second << endl;
}