#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " , " << #y << "=" << y << endl

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t,n, temp;

    cin >> t;

    while (t--) {
        cin >> n ;
        vector<ll> a;
        set<ll> diff;
        ll maxy = INT_MIN;
        ll temp;
        for (ll i = 0; i < n;  i++){
            cin >> temp;
            maxy =  max(maxy, temp);
            a.push_back(temp);
        }

        if (n <= 2){
            cout << 0 << endl;
            continue;
        }

        for (ll i = 0; i < n-1;  i++){
            diff.insert( a[i+1]- a[i] );
        }
        

        if (diff.size() > 2){
            cout << -1 << endl;
            continue;
        }
        if (diff.size() == 1){
           cout << 0 << endl;
           continue;
        }

        ll c1 = *diff.begin();
        ll c2 = *next( diff.begin() );

        if ((c1 >= 0 and c2 >= 0) or (c1 <= 0 and c2 <= 0)) {
            cout << -1 << endl;
            continue;
        }
        
        // Moving the positive value to c1.
        if (c1 < c2 ){
            swap(c1,c2);
        }

        // Since, all the elemnts should be less than m.
        if (maxy > c1 - c2){
            cout << -1 << endl;
            continue;
        }

      // Possible m is `c1 - c2`.
      // We can easily prove this using the fact that a + b (mod)m = a + b or a - (m-b).

       cout <<  c1 - c2 << " " << c1  << endl;
 
}

}