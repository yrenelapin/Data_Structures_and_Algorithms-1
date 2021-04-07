#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;

int main() {
    fastIO;
    ll t, n, m, x;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;

        ll column = (x-1)/n;
        ll row;
        
        if (x % n  != 0){
            row = (x%n)-1;
        }
        else{
            row = (n-1);
        }
        cout << (m*row) + (column+1) << endl;
    }

    return 0;
}