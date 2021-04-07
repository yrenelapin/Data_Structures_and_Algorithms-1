#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;

int main() {
    
    fastIO;
    ll t, n, temp;
    vector<ll> input;
    cin >> t;
    while (t--) {

        cin >> n;
        map<int, int> m;
        for (ll  i = 0; i <n; i++){
            cin >> temp;
            input.push_back(temp);
            m[temp]++;
        }

        int ans = INT_MAX;
        for (int c = 0; c <= n; c++){
                
                int sum2 = 0;
                int sum1 = 0;
                for (ll  i = 0; i <n; i++){

                    if ( m[input[i]] < c){
                        sum1 += m[input[i]];
                        // m[input[i]] = 0;
                    }
                    if ( m[input[i]] >= c){
                        sum2 += ( m[input[i]] - c );
                        // m[input[i]] = 0;
                    }
                 
                }

            ans = min(ans, (sum1+sum2));
        }


    cout << ans << endl;

        

       
    }

    return 0;
}
