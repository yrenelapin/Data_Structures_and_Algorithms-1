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

ll max_value_expr(vl v){
    
    ll n = v.size();

    vl dp1(n+1,INT_MIN);      vl dp2(n+1,INT_MIN);      vl dp3(n+1,INT_MIN);      vl dp4(n+1,INT_MIN);  

    // store maximum value of A[n] in decreasing order in dp1
    frr(i, n-1, 0){
        dp1[i] = max(dp1[i+1], v[i]);
    }

    // store maximum value of A[n]-A[m] in decreasing order in dp2
    frr(i, n-2, 0){
        dp2[i] = max(dp2[i+1], dp1[i+1]-v[i]);
    }

    // store maximum value of A[n]-A[m]+A[j] in decreasing order in dp3
   frr(i, n-3, 0){
        dp3[i] = max(dp3[i+1], dp2[i+1]+v[i]);
    }

    // store maximum value of A[n]-A[m]+A[j]-A[i] in decreasing order in dp4
    frr(i, n-4, 0){
        dp4[i] = max(dp4[i+1], dp3[i+1]-v[i]);
    }

    return dp4[0];


}

void solve() {
  ll n; cin >> n;
  vl v(n); 
  fr(i,0,n-1) cin >> v[i];
  cout << max_value_expr(v);
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