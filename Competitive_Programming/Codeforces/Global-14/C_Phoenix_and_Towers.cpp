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


bool comp(pair<ll,ll>  i, pair<ll,ll>  j){  
    return (i.first < j.first);
}

void solve() {

  ll n, m, x;
  cin >> n >> m >> x;

  ll temp;

  // h contains <element, index>
  vector< pair<ll,ll> > h;

  vl result(n);
  vl input(n);

  fr(i,0,n-1) { cin >> input[i]; 
                h.pb({input[i], i});
  }

  // Sort based on 1st elements
  sort(h.begin(), h.end(), comp);
  

  int temp_m = 1; 



  vl towers(m);

  tra(each, h){

      // Replacing element with its final answer at that corresponding index.
      towers[temp_m-1] += input[each.second];

      result[each.second] = temp_m;

      each.first = temp_m;
      temp_m %= (m);
      temp_m++;

  }
 
 
  sort(all(towers));
  
  if ( abs(towers[0] - towers[m-1]) <= x ){
            cout << "YES\n";
            trav(e,result){
            cout << e << " ";
            }
  }
  else{
      cout << "NO";
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
        cout << "\n";
    }
    return 0;
}