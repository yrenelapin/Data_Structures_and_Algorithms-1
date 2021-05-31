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
ll m,n;

bool is_valid(ll i, ll j){

    return ( ( i >=0  and i < m ) and (j >=0  and j < n ) );
}

ll max_loot(vvl &grid){


    fr(col, 1, n-1){

        fr(row, 0, m-1){
            
            ll a = INT_MIN;

            if (is_valid(row-1, col-1)){
                a = grid[row-1][col-1];
            }

            ll b = INT_MIN;
            if (is_valid(row, col-1)){
                b = grid[row][col-1];
            }

            ll c = INT_MIN;
            if (is_valid(row+1, col-1)){
                c = grid[row+1][col-1];
            }

            grid[row][col] += max(a,max(b,c));

        }

    }

    ll ans = INT_MIN;
    fr(i,0,m-1){
        ans = max(ans,grid[i][n-1]);
    }

    return ans;
    
}

void solve() {

   cin >> m >> n;
  vvl grid(m, vl(n,-1));

  fr(i,0,m-1){
      fr(j,0,n-1){
          cin >> grid[i][j] ;
      }
  }

 cout << max_loot(grid);
  
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