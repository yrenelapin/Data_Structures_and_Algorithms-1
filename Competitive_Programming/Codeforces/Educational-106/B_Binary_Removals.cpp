#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (is_sorted(s.begin(), s.end())){
            cout << "YES\n";
        }
        else{
            ll mid = (s.size()-1)/2;
            ll lone = 0; 
            for (int i = 0;  i<= mid ; i++){
                if (s[i] == '1') lone++;
            }

            ll rone = 0; 
            for (int i = mid+1;  i< s.size() ; i++){
                if (s[i] == '1') rone++;
            }

            if (rone >= lone ){
                 cout << "YES\n";
            }
            else if ( rone < lone ){
                 cout << "NO\n";
            }
        
        }
            
    }

    return 0;
}