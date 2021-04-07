#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl

int main() {
    fastIO;
    int t, n;
    cin >> t;
    while (t--) {

        int ans = 0;
        cin >> n;
        vector<int> v(n);
        for (int  i = 0; i <n; i++){
            cin >> v[i];
        }

        for (int  i = 0; i <n-1; i++){

            int mini = min(v[i], v[i+1]);
            int maxi =  max(v[i], v[i+1]);
                
            while ( 2*mini < maxi ){
                mini *= 2;    // Means we are adding 1 element  in between.
                ans++;
            }

        }

    
        cout << ans << endl;


    }

    return 0;
}
