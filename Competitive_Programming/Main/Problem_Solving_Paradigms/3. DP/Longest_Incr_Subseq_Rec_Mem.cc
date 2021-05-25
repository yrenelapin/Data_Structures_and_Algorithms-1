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
Find the longest increasing subsequence in an array of n elements. 
This is a maximum-length sequence of array elements that goes from left to right,
and each element in the sequence is larger than the previous element. 
*/


/*

1. Subproblem :  Max Length of Longest incre. Subs till Index i --> PREFIXES          // No of subproblems = O(n) 
2. Guess :                       --
3,4. Recurrence & Impl is below
5. Original Problem :  Max Length of Longest incre. Subs till Index n-1      

Time Complexity= O(n)

*/

// Take the Input accordingly.    
vl arr = {6,2 ,5 ,1 ,7 ,4 ,8 ,3, 9,10,11,14};
ll len = arr.size();
vl dp(len+1, -1);


// Recursive Memoisation.
ll long_inc_subs_len(vl arr, ll i){

    if ( dp[i] != -1){
        return dp[i];
    }
    
    ll res = 0;
    if (i == 0){
        res = 1;
    }
    else{

        ll sub_prob = long_inc_subs_len(arr, i-1);
        
        if (arr[i] > arr[i-1])
            { res =  sub_prob + 1; }
        else{
            res = sub_prob;
        }
    }

    dp[i] = res;
    return res;

}

void solve() {
  
    // Our actual Problem is as follows :
    cout << long_inc_subs_len(arr, len-1) << endl;

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