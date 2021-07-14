#include <vector>
#include <iostream>
using namespace std;
typedef unsigned long long int ull;

/*
Given a single integer representing the height (H) of an AVL tree,
write a program to find the minimum number of nodes the tree should contain.
Note: Root node is at height 1.
*/

ull minNodes(int k){
    vector<ull> arr;
    arr.push_back(1);
    arr.push_back(2);
    
    for(int i=2; i<=k; i++){
        arr.push_back( 1 + arr[i-1] + arr[i-2] ) ;
    }
    
    return arr[k];
}

int main(){
    int k;
    cin>>k;
    cout<<minNodes(k)<<"\n";
    return 0;
}
