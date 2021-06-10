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
const ll M = 1e9 + 7;
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

ll fast_pow(ll a, ll p) {
  ll res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % M;
      p /= 2;
    } else {
      res = res * 1ll * a % M;
      p--;
    }
  }
  return res;
}

ll fact(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; i++) {
    res = res * 1ll * i % M;
  }
  return res;
}

ll C(ll n, ll k) {
  return fact(n) * 1ll * fast_pow(fact(k), M - 2) % M * 1ll * fast_pow(fact(n - k), M - 2) % M;
}

void solve() {
  ll n, k; cin >> n >> k;
  map<ll,ll> freq;
  vl v(n); fr(i,0,n-1) { cin >> v[i]; freq[v[i]]++; }
  sort(allr(v));
  ll choose_till = (k-1);   // This is the minimum subscribers.
  ll elem  = v[choose_till];
  
  ll done = 0;
  fr(i, 0, choose_till){
      if (v[i] > elem){
        done++;
      }
  }

  ll rem = k - done;
  ll total_available = freq[elem];
  cout << C(total_available, rem);
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