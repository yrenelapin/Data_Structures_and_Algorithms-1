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

void solve() {
    ll n = 5; ll x = 10;
    vl weights= {2,3,3,5,6};
    
    vpl dp(1<<n);
    // dp[s] contains the pair for the subset `s` of people chosen. 
    // dp[s].fi -> Minimum rides req. for the subset `s`.
    // dp[s].se -> Minimum weight of the Lat ride for the subset `s`.

    // Empty set
    dp[0] = {1,0};

    fr(s,1, (1<<n)-1){

        // initial value: n+1 rides are needed
        dp[s] = {n+1,0};

        // The idea is to go through all people who belong to s and optimally choose the last person p who enters the elevator.
        fr(p,0,n-1){

            // If the set contains the person p.
            if (s & 1 << p){
                
                auto option = dp[s^(1<<p)];  // Remove the person from s.
            
                if (option.se + weights[p] <= x){
                    // add p to an existing ride
                    option.se += weights[p];
                }
                else{
                    // reserve a new ride for p 
                    option.fi ++;
                    option.se = weights[p];
                }

                dp[s] = min(dp[s], option); 
                // Takes the minimum based on 1st argument followed by 2nd argument.

            }

            
        }

    }
    cout << dp[(1<<n)-1].fi;
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