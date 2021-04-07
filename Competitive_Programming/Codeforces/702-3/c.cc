#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


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

        vector<ull> v;
        for (ull i = 1  ; i < cube_root+1 ; i++){
            v.push_back(pow(i,3));
        }

        if ( n==2 )   { cout << "YES\n" ; continue; }
       
        flag = 0;

        for (ull j = 1 ; j< cube_root+1 ; j++){
            
            ull sear =  ( n - pow(j,3)) ;

            if (  binary_search(v.begin(), v.end(), sear)) 
                { cout << "YES"  << "\n"; 
                    flag = 1;
                    v.clear();
                    break;
                }
        }

        if (flag == 0) { v.clear(); cout << "NO" << "\n"; }


    }
}

