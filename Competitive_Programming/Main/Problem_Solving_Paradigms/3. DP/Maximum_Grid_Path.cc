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
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;

// Find a path from the upper-left corner to the lower-right corner of an n × n grid, such that we only move down and right.
// Each square contains a positive integer, and the path should be constructed so that the sum of
// the values along the path is as large as possible.
void solve() {
  ll n;
  cin >> n;
  vvl grid(n, vl(n)); //n*n
  vvl dp(n, vl(n, -1)); 

  fr(i,0,n-1) 
      fr(j,0,n-1) 
        cin >> grid[i][j];
    
  fr(i,0,n-1) {

      fr(j,0,n-1){

          dp[i][j] = grid[i][j];
          
          // 1st row
          if (i == 0 and j >= 1){
              dp[i][j] += dp[i][j-1];
          }

          // 1st column
          if (j == 0 and i >= 1){
              dp[i][j] += dp[i-1][j];
          }

          if (i >= 1 and j >= 1){
              dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
          }




      } 
  }

  cout << dp[n-1][n-1];

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