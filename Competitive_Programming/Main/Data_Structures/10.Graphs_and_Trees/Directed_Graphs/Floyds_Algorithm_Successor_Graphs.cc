#include <bits/stdc++.h>
using namespace std;

/*
Consider a successor graph that only contains a path that ends in a cycle. 
If we begin our walk at the starting node, 
1) what is the first node in the cycle?
2) how many nodes does the cycle contain?
*/

const int n = 100;
vector<vector<int>> adj_list(n+1);

int succ(int x){
    return adj_list[x][0];
}

void Floyd_Algo(int x){

    int a = succ(x);
    int b = succ(succ(x));
    while (a != b) {
        a = succ(a);
        b = succ(succ(b));
    }

    a = x;
    while (a != b) {
        a = succ(a);
        b = succ(b);
    }

    int first = a;
    cout << "\nFirst Node in the cycle: " << first << endl;

    b = succ(a);
    int length = 1;
    while (a != b) {
        b = succ(b);
        length++;
    }

    cout << "\nLength of cycle: " << length << endl;

}


int main(){
    // Sample Input from CP Book.
    adj_list[1] = {2};
    adj_list[2] = {3};
    adj_list[3] = {4};
    adj_list[4] = {5};
    adj_list[5] = {6};
    adj_list[6] = {4};

    Floyd_Algo(1);
}

