#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <string>


typedef unsigned long long int ull;

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        ull n ;
        cin >> n;

        float num = 1;
        float result = num/3;

        ull cube_root = pow(n, result);
        int flag;

        for (ull i = cube_root/2 + 1 ; i < cube_root+1 ; i++){
            
            flag = 0;
            for (ull j = cube_root/2 + 1 ; j< cube_root+1 ; j++){

                if ( (pow(i,3) + pow(j,3)) == n )

                    { cout << "YES"  << "\n"; 
                      flag = 1;
                      break;
                    }
            }

            if (flag == 1) break;
        }
        
        if (flag == 0) cout << "NO" << "\n";


    }
}

