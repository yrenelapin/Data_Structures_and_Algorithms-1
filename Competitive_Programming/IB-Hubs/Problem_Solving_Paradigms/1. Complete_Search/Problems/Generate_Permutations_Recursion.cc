#include <bits/stdc++.h>
using namespace std;


vector<int> permutation;
int n ;


void search( vector<int> &choosen) {

    if ( permutation.size() == n) {

        // Empty set is being printed in the beginning.
        for (int i = 0; i < permutation.size(); i++){
            cout << permutation[i] << " ";
        }

        cout << endl;

    } 
    else {
        for (int i = 0; i <n; i++){

            if ( choosen[i]  == 1) { continue; }
        
            choosen[i] = 1;
            permutation.push_back(i); 
            search(choosen);


            choosen[i]= 0;
            permutation.pop_back();

        }
      
    }
}

int main(){

    cin >> n;
    vector<int> choosen(n, 0);
    // Prints the permutations of the set {0,1,...,n − 1}
    search(choosen);
    
}


// We could actually use the `next_permutation` from STL.
/*
    vector<int> permutation;
    for (int i = 0; i < n; i++) {
    permutation.push_back(i);
    }
    do {
     for (int i = 0; i < permutation.size(); i++){
            cout << permutation[i] << " ";
        }

        cout << endl;

    } while (next_permutation(permutation.begin(),permutation.end()));


*/ 