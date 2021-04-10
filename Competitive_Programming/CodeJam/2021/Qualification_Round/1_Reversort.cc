#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;


ll Reversort(vector<ll> &v, ll n){   
    ll sum = 0;
    for (ll i = 1; i < n ; i++){
        ll j =  ( min_element(v.begin()+ i , v.end()) -  v.begin() )  ;
        sum += (j-i+1);
        reverse( v.begin()+i , v.begin()+j+1 );
    }
    return sum;
}

int main() {
    fastIO;
    ll t, n;
    cin >> t;
    for (ll  j = 1; j <= t ; j++){

        cin >> n ;
        
        // Start using elements from 1,2,...n
        vector<ll> v(n+1);
        for (ll i = 1; i <= n; i++){
            cin >> v[i];
        }

        ll result = Reversort(v, n);
        cout << "Case #" << j << ": " << result << endl;

    }

    return 0;
}