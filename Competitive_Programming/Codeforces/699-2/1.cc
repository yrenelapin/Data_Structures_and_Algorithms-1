#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int x,y;
        cin >> x >> y;
        string s;
        cin >> s;
        
        if ((x >= 0 ) and (y >= 0)){
            int r = count(s.begin(), s.end(), 'R');
            int u = count(s.begin(), s.end(), 'U');
            if (r >= x and u >= y ){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }

            
        if ((x >= 0 ) and (y < 0)){
            int r = count(s.begin(), s.end(), 'R');
            int u = count(s.begin(), s.end(), 'D');
            if (r >= x and u >= abs(y) ){
                cout << "YES" << "\n";
            }
               else{
                cout << "NO" << "\n";
            }
        }
            
        if ((x < 0 ) and (y >= 0)){
            int r = count(s.begin(), s.end(), 'L');
            int u = count(s.begin(), s.end(), 'U');
            if (r >= abs(x) and u >= y ){
                cout << "YES" << "\n";
            }
               else{
                cout << "NO" << "\n";
            }
        }
            
        if ((x < 0 ) and (y < 0)){
            int r = count(s.begin(), s.end(), 'L');
            int u = count(s.begin(), s.end(), 'D');
            if (r >= abs(x) and u >= abs(y) ){
                cout << "YES" << "\n";
            }
               else{
                cout << "NO" << "\n";
            }
        }


    }
}