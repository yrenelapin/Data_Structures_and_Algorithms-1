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

   unordered_map< ll, multiset<ll, greater<ll>> > s;  
   vl u(n), skills(n);

    set<ll> uni;
    fr(i,0,n-1){
        cin >> u[i];
        uni.insert(u[i]);
    }

    fr(i,0,n-1){
        cin >> skills[i];
    }
 
    unordered_map <ll, vector<ll> > sums_uni;
    trav(each, uni){
        sums_uni[ each ].pb(0);
    }

    fr(i,1,n){

        s[ u[i-1]].insert( skills[i-1] );
    }
  
    trav(uni, s){

            trav(each, uni.se){

            ll siz = sums_uni[ uni.fi ].size() - 1;
            ll quan = sums_uni[ uni.fi ][siz]  + each;

            sums_uni[ uni.fi ].pb( quan  );

            }
    }


    vl results(n+1, 0);
    ll sum = 0;

     trav(univ, s){

        fr(k,1, univ.se.size()){
               
               // `req` represents the maximum number of students that can form full teams of size k.
               ll req = univ.second.size()/k;
               req  = req*k;
               sum = sums_uni[ univ.fi ][  req  ];

               results[k] += sum;
           }
         
       }

  

    fr(i, 1, n){
        cout << results[i] << " ";
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