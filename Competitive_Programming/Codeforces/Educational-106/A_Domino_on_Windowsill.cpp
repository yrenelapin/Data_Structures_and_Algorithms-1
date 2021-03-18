#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k1, k2, w, b;
    cin >> t;
    while (t--) {
        cin >> n >> k1 >> k2  >> w >> b;
        ll total = (n*2);
        ll white = k1+ k2 ;
        ll black = total - white;
        if ((w*2 <= white) && (b*2 <= black)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }


    }

    return 0;
}