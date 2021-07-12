#include <bits/stdc++.h>
using namespace std;

/*
K Closest Nodes to Target
Given a list of numbers representing nodes of a tree expect "NULL" which represents
null in Level-Order sequence and two integers T and K, write a program to construct
the Binary Search Tree from this list and find the K closest nodes to T.
*/

int main(){    
    int t, k; cin >> t >> k;
    string temp;
    vector< pair<int,int> > nodes;
    while ( cin >> temp ){  
        if (temp != "null"){
            int cur = stoi(temp);
            nodes.push_back({ abs(cur-t) , cur } );
        }
    }
    sort(nodes.begin(), nodes.end());
    int i = 0 ;
    while(k--){
        cout << nodes[i].second << " ";
        i++;
    }
    return 0;
}
