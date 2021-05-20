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
  string s;
  cin >> n >> s;
  ll zero = count(all(s), '0');
  ll one =  n-zero;
  if (one == zero){
      if ( (ll)sqrt(one*one) == one )
          cout << "DRAW";
          return;
  }
   cout << "BOB";

  }
  

//   ll reverse = 0;
//   ll palin = 1;
//   ll alice = 0, bob = 0;

//   if (n==1 or c== 1){
//       cout << "BOB";
//       return;
//   }
    
//   ll cnt_rev = 0;
//   ll count = 0;

//   while(true){

//     // Alice
//     if ( !(reverse) && !(palin) ){
//         alice +=0;
//         reverse = 1;
//     }
//     else{
//         alice++;
//         count++;
//         reverse = 0;
//         palin ^= 1;
//     }
    
  
//     if (count == c){
//         break;
//     }



//     // Bob
//     if ( !(reverse) && !(palin) ){
//         bob += 0;
//         reverse = 1;
//     }
//     else{
//         bob++;
//         count++;
//         reverse = 0;
//         palin ^= 1;
//     }
    
//     if (count == c){
//         break;
//     }

//   }
 
//   deb2(alice,bob);
//   if (alice > bob){
//       cout << "BOB";
//   }
//   else if (alice < bob){
//       cout << "ALICE";
//   }
//   else{
//       cout << "DRAW";
//   }


 
//}
 
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