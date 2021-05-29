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

// KnapSack

ll max_potions(vl &v){

  ll n = v.size()-1;

  // Let dp[i][k] be the maximum possible health achievable if we consider only the first i potions, and k is the total number of potions taken.
  vvl dp(n+1, vl(n+1, 0));

  // Iterative
  dp[0][0] = 0;

  // Considering till first i potions
  fr(i, 1, n){  

    // No of potions taken
    fr(k, 1, i){
      
      if ( dp[i-1][k-1] + v[i] >= 0){ 
           dp[i][k] = max(  dp[i-1][k-1] + v[i] , dp[i-1][k] );

      }
      else{
      // If taking portion at the ith pos is going to make my health < 0, I will skip it.
        dp[i][k] = dp[i-1][k];
      }

    }

  }

  // fr(i, 1, n){  
    fr(k, 1, n){ 
      deb3(n,k,dp[n][k]);
    
  }
  //}
      
  
  ll ans = 0;
  // fr(k, 1, n){
  //     deb2(k, dp[n][k]);
  //     if ( dp[n][k] != 0){
  //       ans = k;
  //     }
  // }


  return ans;
  
}

void solve() {

  ll n; cin >> n;

  vl v(n+1); fr(i,1,n) { cin >> v[i]; }

  cout << max_potions(v);
  
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    //cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}