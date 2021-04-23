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
  vl v(n);

  vector<int> prefix_xor(n);
    
  // Note that in each step we take only the adjacent elements.
  fr(i,0,n-1)  {            
        
        cin >> v[i];  
        if (i==0)
            prefix_xor[0] = v[0];
        else { prefix_xor[i] = v[i] ^ prefix_xor[i-1] ;  }
  }
    
   // If entire xor == 0, We found sol.   
   bool done =  not(prefix_xor[n-1]);
   
    // Dividing into 3 partitions at i, j.
    fr(i,0,n-1){

         fr(j,i+1,n-2){
            
             // Let array is split into three parts whose xors are x,a,b at i, j, n-1 positions resp.
             // Then x == a== b yields the below conditions.

             // We are doing OR to check if atleast 1 partition exists.

             // Similar to x += y,  x |= y can be used if x, y are castable to `bools`.
             done |= ( prefix_xor[j] == 0 and prefix_xor[i] == prefix_xor[n-1] );


         }
    }


    if (done){
        cout << "YES";
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