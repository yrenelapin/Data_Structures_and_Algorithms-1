#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/* 
Find the longest increasing subsequence in an arr of n elements. This is a maximum-length sequence of arr elements that goes
from left to right, and each element in the sequence is larger than the previous element. 

For example, in the arr
6 2 5 1 7 4 8 3 the longest increasing subsequence contains 4 elements
*/


vector<int> arr = {6,2,5,1,7,4,8,3};

// Let length(k) denote the length of the longest increasing subsequence that ends at position k
vector<int> length(arr.size(),0); //0,1,...len(arr)-1 

int solve(){
    

    for (int k = 0; k < arr.size(); k++){
    
            length[k] = 1; // Initially 1 which means the element itself.
            
            for (int i = 0 ; i < k; i++){   
                
                if (arr[i] < arr[k]) 
                
                length[k] = max(length[k], 1 + length[i]);
                
        }

    }
    
    return *max_element(length.begin(), length.end());


}


int main(){
    cout << solve();
}