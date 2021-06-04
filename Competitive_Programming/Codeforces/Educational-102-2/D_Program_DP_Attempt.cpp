#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll>	vl;
typedef vector<pi>	vpi;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef priority_queue<ll> prq;  // Max priority Queue.
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
const int M = 1e9 + 7;
const ll INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T pw(T a,T p=M-2,T MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}

void build_table(string s, ll n, ll m, vector<vector< unordered_map<ll,ll> >> &dp){



  fr(l,1,n){
    fr(r,1,n){

       if (l > r){
         // Empty map
       }
       else if ( l == r ){  // l-1 or r-1 should be removed.
            
            unordered_map<ll,ll> mymap;
            ll x = 0; mymap[x]++;

            fr(i, 1, l-1){

              if (s[i-1] == '+'){
                x++; mymap[x]++;
              }
              else{
                  x--; mymap[x]++; 
              }
            }

            fr(i, l, n-1){
              if (s[i] == '+'){
                x++; mymap[x]++;
              }
              else{
               x--; mymap[x]++; 
              }
            }

            dp[l][r] = mymap;
       }
       else{  // 2,3

          auto prev =  dp[l][r-1];

          char curr = s[r-1];

          // current char contribution.
          ll x_c = 0;

          fr(i,0,l-2){
            if (s[i] == '+') x_c++;
            else {x_c--;}
          }

          fr(i,l,r-1){
            if (s[i] == '+') x_c++;
            else {x_c--;}
          }

          if (prev[x_c] > 1){
            prev[x_c]--;
          }
          else if (prev[x_c] == 1){
                prev.erase(x_c);
          }

          dp[l][r] = prev;

       }


    }
  }

}

void solve() {
  ll n, m; cin >> n >> m; string s; cin >> s;

  vector<vector< unordered_map<ll,ll> >> dp(n+1, vector<unordered_map<ll,ll>>(n+1));  
  
  build_table(s,n,m, dp);

  ll l, r;
  fr(i,0,m-1) { cin >> l >> r; 
                cout << dp[l][r].size() << endl;
                 //cout << l << " " << r << endl;
                trav(each, dp[l][r]){
                deb2(each.fi, each.se);
                }
              }

}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        //cout << "\n";
    }
    return 0;
}