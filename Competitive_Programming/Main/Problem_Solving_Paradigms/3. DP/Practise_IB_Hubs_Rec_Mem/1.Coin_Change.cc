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

/*
Your friend has given N rupees and told you to get some change for it.
You have an infinite supply of M different valued coins, write a program
to find the number of unique coin combinations that sum up to N.
*/

/*
Subproblem : No of ways to make a sum x using k coins.
Guess : - To include / not include the current coin -> Do both & add count.

Time Complexity : O(MAX_SUM* NO_OF_COINS)
*/

ll coin_change(ll n, ll m, vl v, vvl &dp){

    // If sum became negative or no elements are left, we cant construct, so no of ways is 0.
    // This case need not be stored in the DP.
    if ( (n < 0)  or (m < 0) ){
            return 0;
    }

    // Lookup
    if (dp[n][m] != -1){
        return dp[n][m];
    }

    ll res = 0 ;
    // BASE CASE : Sum = 0 can be always formed in 1 way.
    if ( n == 0 ){
        res = 1;
    }
    else{   

            // To count no of ways to make a sum of `n` using `m` coins (0,1,...m-1)  :

                // 1. We can include the current coin & count no of ways to make a sum of `n-current` using `m` coins.
                  res += coin_change( n-v[m], m , v, dp );

                // 2. We can exclude the current coin & count no of ways to make a sum of  `n` using `m-1` coins.
                  res += ( coin_change(n, m-1, v, dp) );

    }

    dp[n][m] = res;
    return res;
}


void solve() {
  ll m,n;
  cin >> m >>  n;
  vl v(m);
  fr(i,0,m-1) cin >> v[i];

  vvl dp(n+1, vl(m,-1));
   
  // using the first m coins to make sum of n.
  cout << coin_change(n, m-1, v, dp);
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