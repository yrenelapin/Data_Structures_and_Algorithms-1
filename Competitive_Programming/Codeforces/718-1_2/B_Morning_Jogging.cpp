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
  ll n, m;
  cin >> n >> m;
  vvl v;
  ll temp;
  
  multimap<ll,ll> min_ind;

  fr(i,0,n-1) { 
      vl vect;
      ll miny = LLONG_MAX;
      fr(j,0,m-1) { 
        cin >> temp; 
        vect.pb(temp);
        miny = min(miny, temp);
      }

  
    min_ind.insert({miny, i});
 
      v.pb(vect);
  }

  if (n == m ){

        fr(i,0,n-1) { 

            sort(allr(v[i])); 

            ll miny = v[i][m-1];

            // Placing the miny at the ith pos.
            swap( v[i][i], v[i][m-1] );

            // Printing
            fr(j,0,m-1) {
                cout << v[i][j] << " ";

            }
            if (i != n-1) cout << "\n";

        }
  }

  // more points than players
   if (n > m ){ 

       auto itr = min_ind.begin();
       ll count = 0;

        fr(i,0,n-1) { 

            if (count < m){
                ll point_no = itr->second;
                if (point_no == i){

                    sort(allr(v[i])); 

                    ll miny = v[i][m-1];

                    swap(v[i][count],v[i][m-1] );

                }

                itr++;
                count++;
            }

           // Printing
            fr(j,0,m-1) {
                cout << v[i][j] << " ";

            }
            if (i != n-1) cout << "\n";

        }
  }

  // more players than points.
   if (n < m ){

        fr(i,0,n-1) { 
             
            sort(allr(v[i])); 

            ll miny = v[i][m-1];

            swap(v[i][i],v[i][m-1] );

        }

        ll remaining = m-n;   // remaining < m




        fr(i,0,n-1) { 
             
           // Printing
            fr(j,0,m-1) {
                cout << v[i][j] << " ";

            }
            if (i != n-1) cout << "\n";

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