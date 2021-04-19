#include <bits/stdc++.h>
using namespace std;

/*
In a array, Find  the MAXIMUM sum of K Consecutive elements.
*/

int sliding_window(vector<int> &v, int k){

    int curr_sum = 0, max_sum = 0;
   
    for (int i = 0; i <k ; i++){
        curr_sum+= v[i];
    }
    max_sum = curr_sum;
   
    for (int i = k; i < v.size() ; i++){

        curr_sum = (curr_sum + v[i] ) - (v[i-k]);

        if (curr_sum > max_sum){
            max_sum = curr_sum;
        }
    }

    return max_sum;
}

int main(){
    vector<int> v = {5,2,-1,6,-2,7,3};
    int k = 3;
    auto res = sliding_window(v,k);
    cout << res;
}