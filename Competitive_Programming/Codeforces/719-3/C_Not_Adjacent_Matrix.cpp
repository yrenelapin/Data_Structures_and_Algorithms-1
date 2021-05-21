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

void solve() {
  ll n;
  cin >> n;

  if (n == 2){
    cout << -1 << "\n";
    return;
  }

  ll arr[n][n];


  vpl evens;
  fr(i, 0,n-1){
    fr(j,0,n-1){
      // even
      if ( ((i+j) % 2) ==0){
         evens.pb({i,j});
   
      }

    }
  }

  vpl odds;
  fr(i, 0,n-1){
    fr(j,0,n-1){
      // odd
      if ( ( (i+j) % 2) != 0){
         odds.pb({i,j});
      }

    }
  }

  sort(all(odds));
  sort(all(evens));
  ll curr = 1;

  tra(i,odds){
    arr[i.fi][i.se] = curr;
    curr++;
  }

  tra(i,evens){
    arr[i.fi][i.se] = curr;
    curr++;
  }

  fr(i, 0,n-1){
    fr(j,0,n-1){
      cout << arr[i][j] << " ";

    }

    cout << "\n";
  
  }


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
        // cout << "\n";
    }
    return 0;
}   