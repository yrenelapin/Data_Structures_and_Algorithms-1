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
  
  ll n, u,r,d,l; cin >> n;

  vector<ll> v(4);
  vector<bool> res(4, false);
  
  fr(i, 0, 3){
      cin >> v[i];
  } 

  ll maxy =  *max_element(all(v));
  fr(i, 0, 3){
      if ( v[i] == maxy){
          res[i] = true;
      }
  } 

if ( ( v[0] <=  max(v[1], v[3]))  and ( v[0] >= min(v[1], v[3])-2 ) ){
    res[0] = true;
}

  
if ( ( v[2] <=  max(v[1], v[3]))  and ( v[2] >= min(v[1], v[3])-2 ) ){
      res[2] = true;
  }

if ( ( v[1] <=  max(v[0], v[2]))  and ( v[1] >= min(v[0], v[2])-2 ) ){
      res[1] = true;
  }

if ( ( v[3] <=  max(v[0], v[2]))  and ( v[3] >= min(v[0], v[2])-2 ) ){
      res[3] = true;
  }





//    trav(e, res){
//        deb(e);
//    } 

  bool ans = res[0];
  fr(i,1,3){
      ans = ans & res[i];
  }

  if (ans == 0){
      cout << "NO";
  }
  else{
      cout  << "YES";
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