#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <vector>
#include <string>



typedef long long int ll;
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string res  = "";
        for(int i = 1; i<s.size()+1; i++){
            
            // Minimum
            if (i %2 == 1){

                char temp = s[i-1];
                int trr =  temp;

                if (trr == 97 ){    // a
                    // cout << 'b' << "\n";
                    res+= "b";
                }

                if (trr > 97){
                    // cout << 'a' << "\n";
                    res+= "a";
                }  
            }  

            // Maximum
            if (i %2 == 0){
                char temp = s[i-1];
                int trr =  temp;

                if (trr == 122 ){    // a
                    //cout << 'y' << "\n";
                    res+= "y";
                }

                if (trr < 122){
                    // cout << 'z' << "\n";
                    res+= "z";
                } 

            }

        }

        cout << res << "\n";


    }
}