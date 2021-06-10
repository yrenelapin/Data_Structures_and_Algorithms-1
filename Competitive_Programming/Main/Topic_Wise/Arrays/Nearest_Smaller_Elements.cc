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

/*
Consider the problem of finding for each array element the nearest smaller element, i.e.,
the first smaller element that precedes the element in the array. It is possible that no such element exists, 
in which case the algorithm should report this.
*/

// O(n)
void solve() {

  vl v = {1, 3, 4, 2, 5, 3, 4, 2};  
  // vl v = {10,9,8,7,6};  
  ll n = v.size();
  vl result(n);

  stack<ll> s;
  s.push(v[0]); result[0] = -1;
  
  deb(result[0]);
  fr(i,1,n-1){

    ll t = s.top();
    ll cur = v[i];
    if (cur > t){
      s.push(cur);
      result[i] = t;
    }
    else{  
        // It seems O(n^2) becoz of this while loop here. 
        // But since each element is added exactly once to the stack and removed at most once from the stack. 
        // Thus, each element causes O(1) stack operations, and the algorithm works in O(n) time.

        while (!s.empty()){
            if ( s.top() < cur ){
              break;
            }
            else{
              s.pop();
            } 
        }


        if (s.empty()){
            result[i] = -1;  // -1 indicates that there is no smallest element preceeding it at all.
        }
        else{
          result[i] = s.top();
        }

        s.push(cur);
       
    }
  
  }

  fr(i,0,n-1){
    deb2(i,result[i]);
  }



}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    //cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}