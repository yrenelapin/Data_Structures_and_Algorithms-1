#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl

typedef long long int ll;


int main(){
    fastIO
    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> v(n,0);
        for (ll  i= 0; i<n ; i++){
            cin >> v[i];
        }

        ll curr_sum = 0;
        int flag = 1;

        for (ll  i = 0; i<n ; i++){

            ll sum = (i*(i+1))/2LL;
            
            curr_sum += v[i];

            if ( curr_sum < sum ){
                flag = 0;
                break;
            }
        }
    
        if ( flag == 1 || n ==1 ) {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
