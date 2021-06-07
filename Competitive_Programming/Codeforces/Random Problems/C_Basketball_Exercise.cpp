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

ll n; 

ll max_team_height(ll i, ll prev, vvl &dp, vvl &heights){

    if (i >= n){ return 0; }

    if (dp[i][prev] != -1){ return dp[i][prev]; }

    ll res ;

    // Base Case.
    if (i == 0){

        ll f = heights[0][0] + max_team_height(i+1, 0, dp, heights);
        ll s = heights[1][0] + max_team_height(i+1, 1, dp, heights); 
        ll c = max_team_height(i+1, 2, dp, heights);
        ll d = max(heights[1][i] , heights[0][i]);
        res = max(max(f,d), max(s,c));
    }

    else if (i == n-1){  // Last element.


        if (prev == 1){
            res = heights[0][n-1];
        }
        else if (prev == 0){
            res = heights[1][n-1]; 
        }
        else{ // prev == 2
            res = max(heights[0][n-1], heights[1][n-1]);
        }

    }

    else{

            // Last column nothing is choosen.
            if (prev == 2){

                    ll a = heights[0][i] + max_team_height(i+1, 0, dp, heights) ;
                    ll b = heights[1][i] + max_team_height(i+1, 1, dp, heights) ;
                    ll c = max_team_height(i+1,2, dp, heights); 
                    ll d = max(heights[1][i] , heights[0][i]);
                    res = max( max(a, b), max(c,d));
            }

            if (prev == 0){
                    ll a = heights[1][i] + max_team_height(i+1, 1, dp, heights); 
                    ll b = max_team_height(i+1, 2, dp, heights);
                    ll c = heights[1][i];
                    res = max( a, max(b,c));
            }

            else { // prev == 1
                    ll a = heights[0][i] + max_team_height(i+1, 0, dp, heights);
                    ll b = max_team_height(i+1, 2, dp, heights);
                    ll c = heights[0][i];
                    res = max( a, max(b,c));
            }
    }

    return dp[i][prev] = res;
}

void solve() {
  cin >> n; vvl heights(2, vl(n,-1)); 
  fr(i,0,n-1) cin >> heights[0][i];
  fr(i,0,n-1) cin >> heights[1][i];
  vvl dp(n, vl(3,-1)); 
  cout << max_team_height(0, 2, dp, heights);  // 2 - No element is choosen
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