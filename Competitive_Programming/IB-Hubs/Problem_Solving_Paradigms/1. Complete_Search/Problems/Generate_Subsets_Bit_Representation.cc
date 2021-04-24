#include <bits/stdc++.h>
using namespace std;

int n ;

void print_subsets() {
    for (int b = 0; b < (1 << n); b++){
        for (int i = 0;  i <n; i++){
            // If we have 1 at ith bit from right.
            if (b & (1 << i)){
                cout << i << " ";   // Empty set is being printed in the beginning.
            }
        }
        cout << endl;
    }
}

int main(){

    cin >> n;

    // Prints the subsets of the set {0,1,...,n − 1}
    print_subsets();
    
}