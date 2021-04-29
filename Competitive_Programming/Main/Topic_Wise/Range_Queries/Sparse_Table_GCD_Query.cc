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

template<typename T>
inline T gcd(T a, T b)
{
    T c;
    while (b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}



// Input Data
vl v = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
ll n = v.size();
vvl lookup(n, vl(n, 0));


ll query(ll L, ll R)
{
    // Find highest power of 2 that is smaller than or equal to count of elements in given  range.
    ll size = R-L+1;
    ll j = (ll)log2(size);   
  
    // Compute minimum of last 2^j elements with first 2^j elements in range.
    return gcd(lookup[L][j], lookup[R - (1 << j) + 1][j] );
}


// O(nlogn)

/*
We use below properties of GCD:

GCD function is associative [ GCD(a, b, c) = GCD(GCD(a, b), c) = GCD(a, GCD(b, c))], we can compute GCD of a range using GCDs of subranges.

If we take GCD of an overlapping range more than once, then it does not change answer. For example GCD(a, b, c) = GCD(GCD(a, b), GCD(b, c)). 

Therefore like minimum range query problem, we need to do only one comparison to find GCD of given range.

We build a sparse table using the same logic as above. After building the sparse table, we can find all GCDs by breaking given range in powers of 2 and add GCD of every piece to the current answer.
*/
void solve() {

    /* The idea is to precompute gcd of all subarrays of size 2^j where j varies from 0 to Log n.
    We make a table lookup[i][j] such that lookup[i][j] contains gcd of range starting from i and of size 2^j. */

  // If size = 1, (2^0 = 1), The gcd is same as the start element.
  fr(i,0,n-1){
    lookup[i][0] = v[i];
  }

  // Computing values from smaller to larger intervals.

  // Size values range from 1 to 2^j <= n
  for (int j = 1; (1<<j) <= n; j++ ){

      // Compute minimum value for all intervals with size 2^j
      for (int i = 0; (i + (1 << j) - 1) < n; i++) {

        // Just divide the interval into two intervals of size in power of 2.
        lookup[i][j] =  gcd(lookup[i][j - 1], lookup[i + (1<<j-1)][j-1]);

      }

  }

   
    cout << query(0, 2) << endl;
    cout << query(1, 3) << endl;
    cout << query(4, 5) << endl;

}


signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    // cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}