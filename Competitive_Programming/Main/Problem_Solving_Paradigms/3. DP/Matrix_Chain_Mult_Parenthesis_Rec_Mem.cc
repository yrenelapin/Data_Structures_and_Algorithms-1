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
const int M = 1e9 + 7;
const ll INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T pw(T a,T p=M-2,T MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}
/* 
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications,
but merely to decide in which order to perform the multiplications.
https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/

// Subproblem: To multiply i to j Matrices optimally.

ll MatrixChainOrder( ll i, ll j, vl &v, vvl &dp, vvl &parenthesis){

    if (i == j){
        return 0;
    }

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    ll res = INT_MAX;
    
    // Guessing the last multiplication
    fr(k, i, j-1){

        ll temp = MatrixChainOrder(i, k, v, dp, parenthesis) + MatrixChainOrder(k+1, j, v, dp, parenthesis) +  v[i-1]*v[k]*v[j];
        
        if (temp < res){
            res = temp;
            parenthesis[i][j] = k;
        }
        
    }

    dp[i][j] = res;
    return res;

}


// Prints parenthesization in subexpression (i, j)
void printParenthesis(ll i, ll j, vvl parenthesis, char &name)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        cout << name;
        name++;
        return;
    }

    cout << "(";

    // Given two indices i,j, we can find parenthesis position between them at parenthesis[i][j]

    // Recursively put parenthesiss around subexpression
    // from i to parenthesis[i][j].
    printParenthesis(i, parenthesis[i][j], parenthesis, name);  

    // Recursively put parenthesiss around subexpression
    // from parenthesis[i][j] + 1 to j.
    printParenthesis(parenthesis[i][j]+1, j, parenthesis, name);

    cout << ")";
}

void solve() {
    ll n; cin >> n;
    vvl dp(n+1, vl(n+1,-1));  vl v(n); 
    vvl parenthesis(n+1, vl(n+1,-1));  
    fr(i,0,n-1) cin >> v[i];

    // If array len is n, It means there are n-1 matrices.
    cout << MatrixChainOrder( 1, n-1, v, dp, parenthesis) << endl;

    char name ='A';
    printParenthesis(1,n-1, parenthesis,name);
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