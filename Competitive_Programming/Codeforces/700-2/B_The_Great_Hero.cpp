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


void solve() {
  ll a, b, n;
  cin >> a >> b >> n;
  vl A(n), B(n); 
  map<ll,ll> count;
  fr(i,0,n-1) cin >> A[i];
  fr(i,0,n-1) { cin >> B[i];}

  ll total_damage = 0;
  fr(i,0,n-1){
      
      total_damage += (  ceil( B[i]/(float)a ) * A[i] );
  }
  
  // We just need to see if we could find an ordering of
  // monsters to be killed, or to be precise, just the last monster to be killed
  // so that, we can say if the hero succeeds or not.

  // if i+1 montser is the last monster.
  fr(i,0,n-1){

      // If health of hero, just before the last attack is atleast 1, he can kill the last monster too 
      if (  b - (total_damage - A[i] ) > 0){
          cout << "YES" ; return;
      }
  }  

  cout << "NO";


}

int main() {
    fastIO;
    int t = 1;
    cin >>  t; // Comment if only 1 testcase.
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}