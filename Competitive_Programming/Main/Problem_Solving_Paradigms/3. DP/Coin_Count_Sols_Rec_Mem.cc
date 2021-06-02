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
Calculate the total number of ways to produce a sum S using the coins. 
For example, if coins = {1,3,4} and S = 5, there are a total of 6 ways :
• 1+1+1+1+1
• 1+1+3
• 1+3+1
• 3+1+1
• 1+4
• 4+1

It means, we need *NOT* find the *UNIQUE* coin combinations.
So we need not track the position of coins being used. Just sum is sufficient. So 1-D DP.
*/


/*

1. Subproblem :  No of ways to form sum (x)     // No of subproblems = O(S) 
2. Guess :       First coin to be included.     // No of guesses = O(k) where k is the number of coins. -> Time for each subproblem.
3,4. Recurrence & Impl is below
5. Original Problem :  sum( S )

Time Complexity= O(S*k)

*/

// Assuming that maximium sum input is 100.
vl dp(101, -1);


// Recursive Memoisation.
ll coin_sum(ll x, vl coins){

    if ( dp[x] != -1){
        return dp[x];
    }
    
    ll res = 0;
    if (x < 0){
        res = 0;
    }
    else if (x == 0){
        res = 1;
    }
    else{
        
        fr(i, 1, coins.size() ){
            if (x >= coins[i-1])  { res += coin_sum( (x - coins[i-1]), coins ); res %= mod; }
        }

    }


    dp[x] = res;
    return res;

}

void solve() {
    // Take the Input accordingly.    
    vl coins = {1,3,4};
    ll S = 5;
  
    // Our actual Problem is as follows :
    cout << coin_sum(S, coins) << endl;

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