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
template <typename T> T mpow(T x, T n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;

void solve() {
  ll n, m;
  cin >> n >> m;

  map<ll,ll> freq;
  vl a(n);

  fr(i,0,n-1) { cin >> a[i]; freq[(a[i]%m)]++; } 
  

  ll ans = 0;
  tra(each, freq){

      // Grouping all zeroes as a single array.
      if (each.fi == 0){
          ans++;
      }
      
      // Grouping all elements with `mod` value as m/2 into a single array
      else if (2*each.fi == m){
          ans++;
      }
      
      // Else, we will check if  `m-curr` is found.
      // Since we are checking  `2*each.fi < m`, only one among x, m-x can enter this below loop.
      // Thus avoiding re including the already placed elements.
      else if ( ( 2*each.fi < m) or ( freq.find(m - each.fi) == freq.end()) ) {

                // Taking the frequencies.
                ll x = each.se;
                ll y =  freq[ (m - each.fi) ];
            
                ans +=  ( 1 + max(0LL, abs(x - y) - 1LL) );

            }
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