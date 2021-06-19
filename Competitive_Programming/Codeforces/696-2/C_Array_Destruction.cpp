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
vpi ans;
int n; 

bool removed_all(multiset<int> &cp, int mx){

    while(!cp.empty()){
        int sum = mx;
        // Taking the maximum element in the current set of elements.
        auto itr = cp.end(); itr--;
        mx = *itr;
        cp.erase(cp.find(mx));
        if (cp.find(sum-mx) == cp.end()){
            break;
        }
        else{
            cp.erase(cp.find(sum-mx)); 
            ans.pb({mx, sum-mx});
        }
    }

    // If we have performed n operations, It means the array is destructed.
    if (ans.size() == n/2){
        cout << "YES\n";
        auto e = ans.begin();
        cout << e->fi + e->se << endl;
        trav(e, ans){
            cout << e.fi << " " << e.se << endl;
        }

        return 1;
    }



    return 0;
}

void solve() {
  cin >> n; n *= 2; 
  multiset<int> s;
  vi v(n); fr(i,0,n-1) { cin >> v[i]; s.insert(v[i]); }
  sort(all(v));
  
  ans.clear();
  // Since `n` is small, we can try all the possibilities of the 2nd element in the first pair.
  fr(i,0,n-2){
      ans.pb({v[i], v[n-1] });
      multiset<int> cp = s;
      cp.erase(cp.find(v[i]));
      cp.erase(cp.find(v[n-1]));
      if (removed_all(cp, v[n-1])){
          return;
      }

      ans.clear();

  }

  cout << "NO\n";
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
        //cout << "\n";
    }
    return 0;
}
