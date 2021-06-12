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

void generate_next_masks(ll current_mask, ll i, ll next_mask, ll n, 
                            vector<ll>& next_masks){

      // If we reached the last+1 bit, push to masks vector & return.
      if(i == n + 1){
        next_masks.push_back(next_mask);
        return;
      }
      
      // If the current_mask has `i` bit set, In the next_mask, This bit should be 0 (Its already 0), so need to change it. 
      if((current_mask & (1 << i)) != 0)
          generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
      
      // Current mask has `i,i+1` bits empty, In this case, in the next_mask, both i,i+1 are filled or both are empty.
      // Empty case is being handled here, Other case, is handled by below condition.
      if(i != n)
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0)
          generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);      
      
      // Current mask has `i`th bit as 0 & above conditions are not met, We set the ith bit of next_mask to 1.
      if((current_mask & (1 << i)) == 0)
          generate_next_masks
                (current_mask, i + 1, next_mask + (1 << i), n, next_masks);    
}
 
vvl dp(1001, vl(1<<11,-1));  
// dp[i][j] : No of ways to fill the grid from ith column to last column given that ith column has a mask of j.
// `mask` here represents the rows in the ith column that are filled due to the (i-1)th column.
// Notice that since 1 <= n <= 10, we choose the mask as `n` bits to represent all the possibilites with less space & time.

ll fill_grid(ll col, ll mask, const ll m, const ll n){

    // BASE CASE
    // If we reached the `m+1` column, Mask should be 0, meaning we should not overflow the n*m grid.
    if(col == m + 1){
        if(mask == 0)
          return 1;
        return 0;
    }

    // Lookup
    if(dp[col][mask] != -1)
      return dp[col][mask];
 
    ll answer = 0;

    // For filling the grid from current column `col` till end, we will try all the possible ways to fill it,
    // In other words, all the possible masks that come at then next column & add the ways to our final answer.
    vector<ll> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);
  
    for(ll next_mask: next_masks){
        answer = (answer + fill_grid(col + 1, next_mask, m, n)) % M;
    }
 
    return dp[col][mask] = answer;
}

void solve() {
  ll n, m ; cin >> n >> m;

  // Start with column number 1, empty mask.
  cout << fill_grid(1,0,m,n);
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

// Ref : https://youtu.be/lPLhmuWMRag