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
Find a path from the upper-left corner to the lower-right corner of an n × n grid, such that we only move down and right. 
Each square contains a positive integer, and the path should be constructed so that the sum of  the values along the path is as large as possible.
*/


/*
1. Subproblem :  From the current grid(x,y), what is the maximum sum on a path to reach  ( n-1, n-1 ).     // No of subproblems = O(n^2) 
2. Guess :      
3,4. Recurrence & Impl is below
5. Original Problem : From the grid(0,0), what is the maximum sum on a path to reach ( n-1, n-1 ). 

Time Complexity= O(n^2)  since time for each subproblem is O(1) only.

Note that this approach works even for m*n grid.
*/

ll n =  5;
vvl grid =            { { 3, 7, 9, 2, 7 },
                        { 9, 8, 3, 5, 5 },
                        {1, 7, 9, 8 ,5  },
                        {3, 8, 6, 4, 10 },
                        {6, 3, 9, 7, 8, } };
vvl dp(n, vl(n , -1));
vector<vector<pl>> paths(n, vector<pl>(n) );

bool is_valid(ll i, ll j){
    return ( i >=0 and i <n and j >=0 and j < n);
}

// Recursive Memoisation.
ll  max_path( ll x, ll y){

    // Basic Validation. These values of x,y need not be stored in dp.
    if (!is_valid(x,y)){
        return INT_MIN; }

    if ( dp[x][y] != -1){
        return dp[x][y];
    }

    ll res;
    // Base Case
    if ( (x == n-1) && (y == n-1)){
         res =  grid[x][y] ;
    }
    else{
        res =  grid[x][y] ;
        ll right  = max_path(x, y+1) ;
        ll below  = max_path(x+1, y) ;

        if (right <= below){
            res += below;
            pl temp(x+1,y);
            paths[x][y] = temp; 
        
        }
        else{
            res += right;
            pl temp(x,y+1);
            paths[x][y] = temp; 
        }

    }

    dp[x][y] = res;
    return res;

}

void solve() {

    // Our actual Problem is as follows :
    cout << max_path(0, 0) << endl;

    // Printing the Path.
    ll i = 0, j = 0; 
    while (  ( paths[i][j].fi != n-1 ) or ( paths[i][j].se != (n-1) ) ) {
             ll res1 =  paths[i][j].fi;
             ll res2 =  paths[i][j].se;
            cout << res1 << " " << res2 << endl;
            i = res1;
            j = res2;
    }

}


//------------------------------------------------------------------------------------------------------------------------------------//

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