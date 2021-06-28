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
Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money S, our task is to
form the sum S using as few coins as possible.
*/


/*

1. Subproblem :  Min coins to form Sum(x)       // No of subproblems = O(S) 
2. Guess :       First coin to be included.     // No of guesses = O(k) where k is the number of coins. -> Time for each subproblem.
3,4. Recurrence & Impl is below
5. Original Problem :  Sum(n)

Time Complexity= O(S*k)

*/

// Assuming that maximium sum input is 100.
vl dp(101, 0);
vl first_coin(101,0);

// Bottom Up 
ll coin_sum(ll S, vl coins){

    // Base Case. No of coins req to make sum <= 0 is 0.
    dp[0] = 0;

    // Iterating in Topological sort order.
    fr(x, 1, S){
         ll miny  = INT_MAX;
         ll coin_selected ;
         fr(i, 1, coins.size() ){

             // To store the coin being selected, we modified the basic recursion eqn slightly.
              if (x >= coins[i-1]  and miny > ( 1 + dp[ x- coins[i-1] ]) ) { 
                  miny = 1 + dp[ x- coins[i-1] ]; 
                  coin_selected = coins[i-1];
              }
         }

         dp[x] = miny;
         first_coin[x] = coin_selected;
    }


    return dp[S];

}

void solve() {
    // Take the Input accordingly.    
    vl coins = {1,2,3,4,5,6,7,8,9};
    ll S = 50;
  
    // Our actual Problem is as follows :
    cout << coin_sum(S, coins) << endl;

    // Printing the coin selected to form S.
    while (S > 0) {
        cout << first_coin[S] << " ";
        S -= first_coin[S];
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