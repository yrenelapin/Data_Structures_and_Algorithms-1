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

bool isPossible(ll S, vl &v, vvl &dp){

  ll m =  v.size();

  // If sum is 0, Its always possible.
  fr(i, 0, m){
     dp[0][i] = 1; 
  }

    // Note that dp[s][m] indicates whether it is possible to construct a sum of `s` using first `m` elements.
    // Also notice that, here we need to account for 0,1.,...m values becoz, 0 indicates no elements are chose, 1 indicates 1st element, m indicates all m elements are choosen. So 0,1....m-1 are not sufficient.

  
    // For each sum
    fr(s,1, S){

          // check if its possible to construct using first k values.
          fr(k, 1, m){

              // By excluding current element.
              dp[s][k] |=  dp[s][k-1];

              // By including if we can based on the value.
              if (s >= v[k-1])  dp[s][k] |=  dp[ s-v[k-1] ][k-1];
    
    }

  }

  return dp[S][m];
}

void solve() {

  ll m,S; cin >> m >> S;

  vvl dp(S+1, vl(m+1,0));

  vl v(m); fr(i,0,m-1) cin >> v[i];

  // Check if we can make a sum of S using first m elements.
  isPossible(S,v,dp) ? cout << "True" : cout << "False";
  
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
        cout << "\n";
    }
    return 0;
}