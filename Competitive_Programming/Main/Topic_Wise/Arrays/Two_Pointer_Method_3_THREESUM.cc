#include <bits/stdc++.h>
using namespace std;

/*
In a array, Find 3 elements such that their sum is equal to x.
*/

// O(n^2) solution using 2SUM Pointer method.
pair<int,int> two_pointer(vector<int> &v, int x, int index){

    int start = index+1;
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
    pair<int,int> res(-1,-1); // No pair found
    return res;
}

int main(){
    vector<int> v = {10,20,35,50,75,80,85};
    int n = v.size();
    sort(v.begin(), v.end());
    int x = 180;

    for(int i = 0; i<n-2; i++){   

        auto res = two_pointer(v,x-v[i], i);

        if (res.first != -1 and res.second != -1){
            // Indices found
            cout << res.first << " " << res.second << " " << i << endl; return 0;
        }
     
    }

    cout << "Not Possible";
}



// // O( n^2*log(n) ) 
// int main(){
//     vector<int> v = {10,20,35,50,75,80,85};
//     int n = v.size();

//     sort(v.begin(), v.end());

//     int x = 115;
     
//     for(int i=0; i<n-2; i++){           // 0 n-3

//      for(int j=i+1; j<n-1; j++){        // i+1 n-2
         
//          int rem = x - ( v[i] + v[j] );
//                                         // j+1  n-1
//          int l = j+1, r = n-1;
//          while(l <= r){

//              int m = (l+r)/2;
//              if (v[m] == rem){
//                  cout << i << " " << j << " " << m; return 0;
//              }
//              else if (v[m] > rem){
//                     r = m-1;
//              }
//              else{
//                    l = m+1;
//              }

//          }

     
//      }
//     }

//     cout << "Not Possible";

// }