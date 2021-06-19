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

void solve() {
  int n,k; cin >> n >> k;
  vi h(n); fr(i,0,n-1) { cin >> h[i]; }
  
  // This vector contains the min & max starting position of the section at each position.
  vpi val(n);

  // Always starts from ground.
  val[0]   = {h[0], h[0]};
  
  fr(i,1,n-1){

      // Calucalting the min & max values of current section based on previous section values &
      // given conditions.

      // Minimum value of starting point of current section.
      val[i].fi  = max( val[i-1].fi + 1-k, h[i] );
      
      // Maximum value of starting point of current section.
      val[i].se =  min( val[i-1].se + k - 1, h[i] + k-1 );

      // If range is invalid. (min > max)
      if ( val[i].fi > val[i].se ) 
          { cout << "NO"; return; }
  }

  // Last section should always start from ground.
  // So check if its within in the range. 
  if (h[n-1] < val[n-1].fi){
      cout << "NO"; return;
  }

  cout << "YES";
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
