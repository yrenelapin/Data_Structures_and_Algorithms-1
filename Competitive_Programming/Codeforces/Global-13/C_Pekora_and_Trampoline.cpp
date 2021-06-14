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

void solve() {
  ll n; cin >> n;
  vl v(n+1); fr(i,1,n) cin >> v[i];

  vl impact(n+2,0);

  // First we will go through the entire array & at those positions where v[i] != 1,
  // We will note what all indices it will impact to make it 1 itself. 
  fr(i,1,n){  // Greedy approach.
    if (v[i] != 1){

        // Simple observations
        if (i + v[i] > n){
            fr(j, i + 2, n){
                impact[j]++;}
        }
        else{
            fr(j, i + 2, i + v[i]){
                impact[j]++;}
        }
    }
  }
  
    ll ans = 0;

    // Now traversing the array & impact at a time & compare their values
    // & see if impact of previous ones is able to make the current element `1` or not 
    // & do the appropriate thins accordingly for two cases as shown below.
    fr(i, 1, n ){
        if (v[i] - 1 - impact[i] > 0)
            ans += (v[i] - 1 - impact[i]);
        else 
            // Impact is more than required, It will contribute the remaining amount to the next one too since it becomes 1.
            // To get clarity, Work out an example.
            impact[i + 1] += (impact[i] - v[i] + 1);
    }

  cout << ans;
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}