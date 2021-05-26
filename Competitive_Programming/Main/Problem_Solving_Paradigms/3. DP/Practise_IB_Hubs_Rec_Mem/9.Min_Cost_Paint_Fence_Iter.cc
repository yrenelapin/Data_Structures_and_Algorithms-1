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
    Sub Problem : Minimum cost to paint the ith column. 
    -> We start from the last column & paint the previous columns. We are guessing the color of the ith column.
    -> Note that there is no need to maintain a separate DP table here.
*/

ll min_cost( vvl &matrix, ll n ){

    frr(i, n-2, 0){

        // painting ith column with color 0 & chosing among the other two colors for (i+1)th column. 
        matrix[i][0] += min( matrix[i+1][1], matrix[i+1][2] );

        // painting ith column with color 1 & chosing among the other two colors for (i+1)th column. 
        matrix[i][1] += min( matrix[i+1][0], matrix[i+1][2] );

        // painting ith column with color 2 & chosing among the other two colors for (i+1)th column. 
        matrix[i][2] += min( matrix[i+1][1], matrix[i+1][0] );
    }
        
    ll res =  min( min (matrix[0][0], matrix[0][1] ), matrix[0][2] ) ;

    return res;

}

void solve() {
  ll n; cin >> n;
  vvl matrix(n, vl(3,0) );
  fr(i,0,n-1) 
    fr(j,0,2)
        cin >> matrix[i][j];

   cout << min_cost(matrix, n);
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