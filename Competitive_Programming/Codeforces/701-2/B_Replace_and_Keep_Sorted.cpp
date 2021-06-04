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

  
void fill_table( vvl &dp, vl v , ll n, ll k){

  fr(l, 1, n){
    fr(r, 1, n){

      if ( l == r ){
        dp[l][r] =  k-1; 
      }

      else if (l > r){
        dp[l][r] = 0;
      }

      else if ( l+1 == r ){
          ll curr = v[r-1];
          dp[l][r] = (curr-2) + (k - v[l-1] - 1);   
      }
      else{

          ll prev = dp[l][(r-1)];

          ll last_1 = v[r-2];
          ll last_2 = v[r-3];
          ll to_remove = (k - last_2 - 1);
          prev -= (to_remove);

          ll curr = v[r-1];
          ll cont_last_1 = (last_1 - last_2 -1) + (curr-last_1-1);
          ll cont_curr = k - last_1 -1;

          dp[l][r] = prev + cont_curr + cont_last_1 ;


      }


    }
  }

}

void solve() {
  ll n, q,k; cin >> n >> q >> k;

  vl v(n); 
  fr(i,0,n-1) cin >> v[i];

  vvl dp(n+1, vl(n+1, 0));
  
  fill_table(dp,v, n, k);

  fr(j, 1, q){

      ll left, right;
      cin >> left >> right;
      cout << dp[left][right] << endl;

  }
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
        //cout << "\n";
    }
    return 0;
}