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

ll min_cost(ll c1, ll c2, ll c3, ll n, vvl &matrix, vl &dp){

    if (n < 0){
        return 0;
    }

    if (dp[n] != -1){
        return dp[n];
    }

    ll res1 =  INT_MAX;
    ll res2 =  INT_MAX;
    ll res3 =  INT_MAX;

    // Base Case
    if (c1 == 0 and c2 == 0 and c3 == 0){
        res1 = 0; res2 = 0 ; res3 = 0;
    }
    else{
        
        if ( c1 == 1)
            res1 = matrix[n][0] +  min_cost(0,1,1, n-1, matrix, dp);
        
        if ( c2 == 1)
            res2 = matrix[n][1] +  min_cost(1,0,1, n-1, matrix, dp);
        
        if ( c3 == 1)
            res3 = matrix[n][2] +  min_cost(1,1,0, n-1, matrix, dp); 
    }

    dp[n] = min( res1, min( res2, res3) );

    return dp[n];

}

void solve() {
  ll n; cin >> n;
  vl dp(n+1, -1);  vvl matrix(n, vl(3,-1));
  fr(i,0,n-1) 
    fr(j,0,2)
        cin >> matrix[i][j];
   ll c1 = 1, c2 = 1, c3 = 1;
   cout << min_cost(c1,c2,c3, n-1, matrix, dp);
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