#include <bits/stdc++.h>
using namespace std;

/*
In a SORTED array, Find a pair of elements such that their sum is equal to x.
*/

pair<int,int> two_pointer(vector<int> &v, int x){

    int start = 0;
    int end = v.size()-1;
    while (start < end ){ // They should not be equal since we need a pair of elements.
        
        if (v[start] + v[end] == x) {
            pair<int,int> res(start, end);
            return res;
        }

        if (v[start] + v[end] < x){
            start++;
        }

        else{
            end--;
        }

    }
    pair<int,int> res(-2,-2); // No pair found
    return res;

}

int main(){
    vector<int> v = {10,20,35,50,75,80,85};
    int x = 70;
    auto res = two_pointer(v,x);
    // Indices found
    cout << res.first << " " << res.second << endl;
}