#include <bits/stdc++.h>
using namespace std;

/*
In a array of NON Negative Numbers, Find the subarray whose Sum is equal to K.
*/

pair<int,int> sliding_window_variant(vector<int> &v, int k){

    int curr_sum = 0;
    int window_start = 0, window_end = 0;

    while (window_end <= v.size()){

        // If sum is more, We remove the elements from the beginning
        while ( (curr_sum > k) && (window_start < window_end-1) ){
            curr_sum -= v[window_start];
            window_start++;
        }

        if( curr_sum == k){
            pair<int,int> res(window_start, window_end-1);
            return res;
        }

        // It means the curr_sum < k, So increase the size of the window.
        if( window_end < v.size()){
            curr_sum += v[window_end];
        }

        window_end++;

    }

    // If no such subarray exists, Just return this.
    pair<int,int> res(-2,-2);
    return res;
    
}

int main(){
    vector<int> v = {10,44,20,2,10,5};
    int k = 66; 
    auto res = sliding_window_variant(v,k);
    // Prints the start & end indices of subarray.
    cout << res.first << " " << res.second;
}