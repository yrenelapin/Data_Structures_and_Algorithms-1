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
  ll n, m ; cin >> n >> m;
  vl a(n); fr(i,0,n-1) cin >> a[i];

  vl left(n, INF); // left[i] denotes the minimum time it takes if we use only left-right trains(1)

  set<ll, greater<ll>> r_trains;

  // Going from left to right.
  fr(i,0,n-1){
    
    // There is a train at city i.
    if (a[i] != 0){
        left[i] = 0;

        if (a[i] == 1){
            r_trains.insert(i);
        }
    }
    else{
        
        if (r_trains.size() != 0)
            left[i] = (i- *r_trains.begin());
    }

  }

  left[0] = 0; // 1st city has train always.

//   trav(e,left){
//       deb(e);
//   }


  vl right(n, INF); 

  set<ll> l_trains;

  if (a[n-1] != 0 ){
      right[n-1] = 0;
  }

  if (a[n-1] == 2){
      l_trains.insert(n-1);
  }

  frr(i,n-2,0){
    
    // There is a train at city i.
    if (a[i] != 0){
        right[i] = 0;

        if (a[i] == 2){
            l_trains.insert(i);
        }
    }
    else{
        
        if (l_trains.size() != 0)
            right[i] = abs(i- *l_trains.begin());
    }

  }

//   trav(e,right){
//       deb(e);
//   }


  ll q;
  fr(i,0,m-1){
    cin >> q; q--;
    ll res = min(left[q], right[q]);
    if (res == INF){
        cout << -1 << " ";
    }
    else{
        cout << res << " ";
    }
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