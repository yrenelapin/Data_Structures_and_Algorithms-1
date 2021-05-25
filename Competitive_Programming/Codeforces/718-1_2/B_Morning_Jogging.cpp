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

// Sorting based on the lengths
bool comp(pl i, pl j){
  return (i.fi < j.fi);
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vvl v(n, vl(m,0));

  vector<pl> to_sort;
  fr(i,0,n-1) { 
      fr(j,0,m-1) { 
       cin >> v[i][j];
       // Storing the Length & checkpoint.
       to_sort.pb( { v[i][j], i } );
    }
  }
  
   sort(all(to_sort), comp);

    ll k = 0;
    vvl result(n, vl(m,0));

    // Taking the first m values.
    fr( i, 0, m-1){
        
        // Go to the row indicated by the pair in the sorted vector & 
        // `k` takes care of putting `m` minimum values in `m` different columns.
        result[ to_sort[i].se ][k++] = to_sort[i].fi;
    } 
    

    // Putting remaining values.
    for( ll i = m; i<n*m; i++){

       
        for(ll j = 0; j<m; j++){

             // If it is not yet filled.
            if( result[to_sort[i].se][j] == 0) {

                result[to_sort[i].se][j] = to_sort[i].fi;
                
                break;
            }

        }
    }


    // Printing the result
    fr(i,0, n-1){
        fr(j,0,m-1){
            cout << result[i][j] << " "; }
            cout << endl;
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
    }
    return 0;
}