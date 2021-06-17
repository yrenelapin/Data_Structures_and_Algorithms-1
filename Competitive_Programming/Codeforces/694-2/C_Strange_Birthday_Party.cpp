#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long                                   // Comment it out if default `int` is req. 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(int (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(int (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
using namespace std;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<pi>	vpi;
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef priority_queue<int> prq;                          
const int M = 1e9 + 7;
const int INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   
//-----------------------------------------------------------------------------------------------------//
bool is_prime(int n){ 
    if (n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}    

vi prime_factors(int n){
    vi res;
    for(int i = 2; i*i <= n; i++){
        while (n % i == 0){
            res.pb(i);
            n /= i;  
        }
    }
    if (n > 1) res.pb(n);
    return res;
}

vi sieve_erato(int n){
    /*sieve[k]  = 0  -> k is prime
      sieve[k] != 0  -> k is not a prime & one of its prime factors is sieve[k].*/
    vi sieve(n+1);
    fr(i,2,n){
        if (sieve[i]) continue;
        for(int j = 2*i; j <= n; j+=i ){
            sieve[j] = i;
        }
    }
    return sieve;
}

int gcd(int a, int b){
    int c;
    while (b){
        c = b; 
        b = a % b;
        a = c;
    }
    return a;
}

int modpow(int a, int p = M-2, int MOD = M ){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}
//-----------------------------------------------------------------------------------------------------//

// Min cost to give presents starting from ith till last friend.
int min_cost(int i, vi &chosen, vi &dp, vi &k, vi &c, int n, int m){

    if (i == n){
        return 0;
    } 

    if (dp[i] != -1){
        return dp[i];
    }

    int res;
    if (i == n-1){  
        // For Last friend, we can simply choose minimum value among presents left and dollar amount 
        int tmp = INF;
        int indx =  k[i];
        fr(i,0,indx-1){
            if (chosen[i] == 0){
                tmp = min(tmp, c[i]);
            }
        }
    
        tmp = min(tmp, c[k[i]-1]);
        res = tmp;
    }
    else{ // Try all the possibilities.

        int indx =  k[i];

        // // Paying dollars case.
        // int tmp = c[k[i]-1] + min_cost(i+1, chosen, dp, k, c, n, m); 
        
        int tmp = INF;
        fr(i,0,indx-1){ // Trying all the presents.
            if (chosen[i] == 0){
                chosen[i] = 1;
                tmp = min(tmp, c[i] + min_cost(i+1, chosen, dp, k, c, n, m)     );
            }
        }

        res = tmp;
    }
    
    //deb2(i, dp[i]);
    return dp[i] = res;
}

void solve() {
  int n, m; cin >> n >> m;
  // int dp[n][n]; memset(dp,-1, sizeof(dp));
  vi k(n); fr(i,0,n-1) { cin >> k[i]; }
  vi c(m); fr(i,0,m-1) { cin >> c[i]; }
  vi dp(n,-1);
  vi chosen(m, 0);

  cout << min_cost(0, chosen, dp, k, c, n, m) << endl;

    fr(i,0,n-1){
      cout << i << " " <<  dp[i] <<  endl;
  }
}

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
