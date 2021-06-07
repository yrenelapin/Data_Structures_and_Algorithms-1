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

// Subproblem: Minimum no of operations to reach 0 from sum x.
ll min_operations(ll n){

    // This INT_MAX is important becoz when checking for a quantity that has not been computed yet,
    // We should not give 0.
    vl dp(n+1, INT_MAX);

    dp[0] = 0;

    // For sums from 1 to n.
    fr(i,1,n){

        string t = to_string(i); 
        ll m = t.size()-1;

        // For each digit in current sum, trying all the possiblities.
        // Since we are taking the digits of `i` only here, we need not check if `i-curr >=0`
        ll ans = INT_MAX;
        fr(j,0, m){
            ll cur =  t[j] - '0';  
            ans = min(ans, 1 + dp[i-cur]);
        }
        dp[i] = ans;

    }

    return dp[n];

}

// DP
void solve() {
  ll n; cin >> n;
  cout << min_operations(n);
}

// This greedy solution works too
// void solve() {
//   ll n; cin >> n;
//   ll cnt = 0;
//   while(n > 0){
//       string t = to_string(n); ll m = t.size()-1;
//       ll maxy = INT_MIN;
//       fr(i,0, m){
//           ll cur =  t[i] - '0';
//           maxy = max(maxy, cur);
//       }
//       n -= maxy;
//       cnt++;
//   }

//   cout << cnt;
// }

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