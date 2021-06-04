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



ll min_days_rest(vl v, vvl &dp)
{
    // dp[i][j] indicates : Minimum days of rest if i days passed & on ith day `j` is the action taken. Meaning on j :
    // 2 - rest
    // 1 - gym
    // 0 - contest

    // 0 days passed, We cant take contest/gym so they are kept INF.
	dp[0][0] = dp[0][1] = INF;

    // 0 days passed, If I take rest today, It wont account for count, so keep 0.
    dp[0][2] = 0;

    ll n = v.size();

    // For each day
	for (int i = 1; i <= n; ++i)
	{   
		ll x =  v[i-1];

        // If 0th bit (LSB) of x == 1, contest is possible
		if ( ( x & (1 << 0)) )

            // If i days passes, to take contest today, min is to be cosidered for previous days with 1/2
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]);

		else

            // Not possible
			dp[i][0] = INF;


        // If 1st bit of x == 1, gym is possible
		if ((x & (1<<1)))

            // If i days passes, to take contest today, min is to be cosidered for previous days with 0/2
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);

		else
            // Not possible
			dp[i][1] = INF;


        // Rest can be taken independent of `x`. But to minimize the rests, we use below:
        
        // To take a rest today, I will add 1 to the minimum among the previous days activities.
		dp[i][2] = 1 + min(dp[i-1][2], min(dp[i-1][0],dp[i-1][1]));
 
	}

    // Minimum days of rest if n days passed is minimum among the cases where on nth day 0/1/2 are done. 
	return min( dp[n][0] , min(dp[n][1], dp[n][2]));
}

void solve() {
  ll n; cin >> n;
  vvl dp( n+1, vl(3,-1));  vl v(n); 
  fr(i,0,n-1) cin >> v[i];
  cout << min_days_rest(v, dp);
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