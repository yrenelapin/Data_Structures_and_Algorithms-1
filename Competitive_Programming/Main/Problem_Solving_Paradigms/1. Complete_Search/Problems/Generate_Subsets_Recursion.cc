#include <bits/stdc++.h>
using namespace std;


vector<int> subset;
int n ;

void search(int k) {

    if (k == n) {
        // Empty set is being printed in the beginning.
        for (int i = 0; i < subset.size(); i++){
            cout << subset[i] << " ";
        }

        cout << endl;

    } 
    else {
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
}

int main(){

    cin >> n;

    // Prints the subsets of the set {0,1,...,n − 1}
    search(0);
    
}