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

/* Ref: https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/   */

ll n;

/*
Initially, It seems like there is no optimal substructure, 
But once we fix a Starting point, We can see that, Optimal Substructure is present.

Subproblem : Given a starting point, What is the longest distance ?
Guess : The starting point (Hint : Try all! )
Original Problem : Maximum among lengths from all starting points.
*/

ll LongestPath(ll i, ll j, vvl &grid, vvl &dp){

    if ( not( ( i >=0  and i < n ) and (j >=0  and j < n ) ) ){
        return 0;
    }

    if (dp[i][j] != -1){
      return dp[i][j];
    }

    ll u = INT_MIN, d = INT_MIN, l = INT_MIN, r = INT_MIN;

    // Since all numbers are unique and in range from 1 to n*n,
    // there is atmost one possible direction from any cell
    if (  (j < n-1 )   and  ( 1+ grid[i][j] == grid[i][j+1] ) ){
        r = 1 + LongestPath(i,j+1, grid, dp);
    }

    if (  (j > 0 )   and  ( 1+ grid[i][j] == grid[i][j-1] ) ){
        l = 1 + LongestPath(i,j-1, grid, dp);
    }

      if (  (i < n-1 )   and  ( 1+ grid[i][j] == grid[i+1][j] ) ){
        d = 1 + LongestPath(i+1,j, grid, dp);
    }

      if (  (i > 0 )   and  ( 1+ grid[i][j] == grid[i-1][j] ) ){
        u = 1 + LongestPath(i-1,j, grid, dp);
    }

    vl temp = {u,d,l,r,1};
    ll res = *max_element(all(temp));
    return dp[i][j] = res;
}

void solve() {
  cin >> n;
  vvl grid(n, vl(n,-1));
  vvl dp(n, vl(n,-1));

  fr(i,0,n-1){
      fr(j,0,n-1){
          cin >> grid[i][j] ;
      }
  }

  ll ans = 1; ll temp;

  // Choosing the starting point
  fr(i,0,n-1){
    fr(j,0,n-1){
      if (dp[i][j] == -1){
          temp = LongestPath(i,j,grid,dp);
      }
      ans = max(ans,temp);
  }}

  cout << ans;

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