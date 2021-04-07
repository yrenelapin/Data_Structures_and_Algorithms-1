#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef unsigned long long ll;

ll gcd(ll a, ll b){
    if( a<0 ) a = -a;
    if( b<0 ) b = -b;
    while( b!=0 ){
        a %= b;
        if( a==0 ) return b;
        b %= a;
    }
    return a;
}

int main() {
    fastIO;
    ll t;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll gcdd = 1;

        for (ll j = n; ; j+= (gcdd)){

            ll sum = 0;
            string str = to_string(j);
            for (ll i = 0 ; i < str.size(); i++){
            string temp(1,str[i]);
                sum += stoi( temp );
            }
            gcdd = gcd(sum,j);

            if ( gcdd > 1){
                cout << j << endl;
                break;
            } 

        }


    }

    return 0;
}