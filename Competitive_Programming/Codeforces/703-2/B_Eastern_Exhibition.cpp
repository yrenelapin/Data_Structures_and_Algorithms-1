#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl

typedef long long int ll;

ll t, n;

ll count(ll arr[]){
    sort(arr, arr+n);
    ll right_median  =  (n) / 2  ;
    ll left_median   =  (n - 1) / 2   ;
    return ( arr[right_median] - arr[left_median] ) + 1 ;
}



int main(){
    fastIO
 
    cin >> t;
    while(t--){
        cin >> n;
        ll x[n]; 
        ll y[n];
        for (ll  i= 0; i<n ; i++){
            cin >> x[i] >> y[i];
        }

        cout <<  count(x)*count(y) << endl;

    }
}