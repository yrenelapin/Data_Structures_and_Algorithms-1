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
template <typename T> T mpow(T x, T n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;

//------------------------------------------------------------------------------------------------------------------------------------//


/*
Optimal evaluation of associative expression A[0] · A[1] · · · A[n − 1] — e.g., multiplying
rectangular matrices 
*/

vvl dp(n, vl(n,-1));

// Recursive Memoisation.

// subproblem i to j-1 multiplications. i.e. Substring[i:j]
ll optimal(ll i , ll j){

    if ( dp[i][j] != -1){
        return dp[i][j];
    }
    
    ll res ;
    if (j = i+1){
        res = 0;
    }
    else{
        
        ll miny  = INT_MAX;

        // Guessing the last multiplication.
        fr(k, i+1, j-1){

            // Notcie that `cost_for_multipication` of two matrices dependson given conditions.
            miny = min( miny, optimal(i,k) + optimal(k,j) + cost_for_multi( (A[i] · · · A[k − 1]) by (A[k] · · · A[j − 1]) ) );
        }

        res = miny;

    }

    dp[i][j] = res;
    return res;

}

void solve() {
    // Take the Input accordingly.    

    // Our actual Problem is as follows :
    cout << optimal(0, n);

}


//------------------------------------------------------------------------------------------------------------------------------------//

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