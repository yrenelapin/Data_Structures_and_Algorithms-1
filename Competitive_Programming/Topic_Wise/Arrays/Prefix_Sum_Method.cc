#include <bits/stdc++.h>
using namespace std;

/*
Find the sum of the numbers in a subarray within the given ranges.
*/

int subarray_sum_with_prefix_sum(vector<int> &v, int start_index, int end_index){

    vector<int> prefix_sum(v.size());

    prefix_sum[0] = v[0];

    for (int i = 1; i < v.size() ; i++){
        prefix_sum[i] = v[i] + prefix_sum[i-1];
    }

    // Range sum = prefix_sum_array[end_range] - prefix_sum_array[start_range-1]

    return (prefix_sum[end_index] -  prefix_sum[start_index-1]) ;
}

int main(){
    vector<int> v = {5,2,-1,6,-2,7,3};
    int start_index = 3;
    int end_index = 5;
    cout << subarray_sum_with_prefix_sum(v,start_index,end_index);
}