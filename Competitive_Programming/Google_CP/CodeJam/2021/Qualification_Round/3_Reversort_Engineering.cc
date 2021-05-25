#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;


int main() {
    fastIO;
    ll t, n, c;
    cin >> t;

    for (ll  j = 1; j <= t ; j++){

        cin >> n  >> c;
        
        if ( (c < n-1) or  ( c >  ( (n*(n+1)/2) - 1 )  )  ){
            cout << "Case #" << j << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        else{
                vector<ll> v(n), ans(n);

                // v is an array of indices.
                for (ll i = 0; i < n; ++i){
                    v[i] =  i;
                }
                

                // Doing n-1 iterations. 
                for (ll i = 0; i < n-1; ++i){
                    
                    // At an index, i
                    ll left = n-2-i;

                    ll max_possible_cost_here = n-i;

                    ll used_here = min(max_possible_cost_here, c-left);
                    c -= used_here;

                    // Reversing the index array.
                    reverse(v.begin()+i, v.begin()+i+used_here);

                    // Updating the actual array using this index array.

                    ans[v[i]] = i+1;
                }

                ans[v[n-1]] = n;
    
                cout << "Case #" << j << ": ";
                for (ll i = 0; i < n; i++){
                     cout << ans[i] << " ";
                }
                cout << endl;
            
        }

    }
    

    return 0;
}