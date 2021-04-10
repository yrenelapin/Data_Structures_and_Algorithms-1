#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;


int main() {
    fastIO;
    ll t;
    cin >> t;
    for (ll  j = 1; j <= t ; j++){

        ll x, y;
        string s;
        cin >> x >> y >> s;

        vector<string> v;
        for (ll i = 0; i < s.size() ; i++){

            if (s[i] != '?'){
            string temp(1, s[i]);
            v.push_back(temp);
            }

        }

        unordered_map<string,ll> cost;
        cost["CJ"] = x;
        cost["JC"] = y;
        cost["CC"] = 0;
        cost["JJ"] = 0;
       
        if (v.size() == 0){
            cout << "Case #" << j << ": " << 0 << endl;
            continue;
        }
        
        ll total = 0;
        for (ll i = 0 ; i < v.size()-1 ; i++){
            string temp = (v[i]+v[i+1]);
            total += cost[temp];
        }

      
        
        cout << "Case #" << j << ": " << total << endl; 

    }

    return 0;
}