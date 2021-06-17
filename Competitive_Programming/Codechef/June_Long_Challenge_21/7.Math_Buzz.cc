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
const int M = 998244353;
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
ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
    if (p % 2 == 0) {
        a = a * 1ll * a % M;
        p /= 2;
    } else {
        res = res * 1ll * a % M;
        p--;
    }
    }
    return res;
}

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
    res = res * 1ll * i % M;
    }
    return res;
}

ll C(ll n, ll k) {
    return fact(n) * 1ll * fast_pow(fact(k), M - 2) % M * 1ll * fast_pow(fact(n - k), M - 2) % M;
}

// Returns (a * b) % mod
long long moduloMultiplication(long long a, long long b,
							long long mod)
{

	// Initialize result
	long long res = 0;

	// Update a if it is more than
	// or equal to mod
	a %= mod;

	while (b) {

		// If b is odd, add a with result
		if (b & 1)
			res = (res + a) % mod;

		// Here we assume that doing 2*a
		// doesn't cause overflow
		a = (2 * a) % mod;
		b >>= 1; // b = b / 2
	}
	return res;
}

// C++ function for extended Euclidean Algorithm
long long int gcdExtended(long long int a, long long int b,
						long long int* x,
						long long int* y);

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't exists
long long int modInverse(long long int b, long long int m)
{

	long long int x, y; // used in extended GCD algorithm
	long long int g = gcdExtended(b, m, &x, &y);

	// Return -1 if b and m are not co-prime
	if (g != 1)
		return -1;

	// m is added to handle negative x
	return (x % m + m) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
long long int gcdExtended(long long int a, long long int b,
						long long int* x,
						long long int* y)
{

	// Base Case
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}

	// To store results of recursive call
	long long int x1, y1;

	long long int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

// Function to compute a/b under modlo m
long long int modDivide(long long int a, long long int b,
						long long int m)
{

	a = a % m;
	long long int inv = modInverse(b, m);
	if (inv == -1)
		// cout << "Division not defined";
		return 0;
	else
		return (inv * a) % m;
}

// Function to calculate nCr % p
ll nCr(ll n, ll r, ll p)
{

	// Edge Case which is not possible
	if (r > n)
		return 0;

	// Optimization for the cases when r is large
	if (r > n - r)
		r = n - r;

	// x stores the current result at
	long long int x = 1;

	// each iteration
	// Initialized to 1 as nC0 is always 1.
	for (ll i = 1; i <= r; i++) {

		// Formula derived for calculating result is
		// C(n,r-1)*(n-r+1)/r
		// Function calculates x*(n-i+1) % p.
		x = moduloMultiplication(x, (n + 1 - i), p);
	
		// Function calculates x/i % p.
		x = modDivide(x, i, p);
	}
	return x;
}


void solve() {
  ll r,k; cin >> r >> k;
  vl a(k); fr(i,0,k-1) cin >> a[i];
  vl p(k); fr(i,0,k-1) cin >> p[i];
  ll ans = 0;
  fr(i,0,k-1){
      //ll com =  C(a[i]%M, r%M);
      ll com = nCr(a[i]%M, r%M, M);
      ll temp = ( p[i]*com )% M;
      //deb3(p[i],com,temp);
      ans = ( ans + temp )%M; 
  }

  cout << ans;
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