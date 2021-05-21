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

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;


bool isgood(vl v){

  ll sum = 0;
  fr(i,0,v.size()-1){
    sum += v[i];
  }

  if (sum % 2 == 1){
    return 1;
  }

  // It requires atleast these many bits `MAX_NUM*MAX_ARRAY_SIZE /2 + 1`
  bitset<100001> b;

  b[0] = 1;
  // Representing the subsets.
  fr(i,0,v.size()){
      b |= (b << v[i] );
  }

  // We now check if there is a subset whose sum is `sum/2`
  return not ( b[sum/2] );

}

void solve() {
  ll n;
  cin >> n;
  vl v(n);
  int odd = 0; int index = 0;
  fr(i,0,n-1) { cin >> v[i]; if (v[i] %2 == 1) {odd = 1; index = i+1;} }

  // Check if the array is already good.
  if (isgood(v)){
    cout << 0;
    return;
  }

  // So, sum is even. Remove an odd element
  while(odd == 0){
      fr(i,0,n-1) {  v[i] /= 2; if ( v[i] %2 == 1) {odd = 1; index = i+1; break;} }
  }

  cout << 1 << "\n" << index; 

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