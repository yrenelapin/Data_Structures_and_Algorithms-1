#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int occ_11 = s.find("11");
        int occ_00 = s.rfind("00");
        
        // If both "00" && "11" existed & last occurence of "00" is later than the first occurence of "11".
        if ( (occ_11 < occ_00)  && (occ_00 != -1) && (occ_11 != -1)){
            cout << "NO\n";}
        else { cout << "YES\n";}

    }
}