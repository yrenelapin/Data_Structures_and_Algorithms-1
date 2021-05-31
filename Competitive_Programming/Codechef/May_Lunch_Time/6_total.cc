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

vi primes;   int n; int cc = 0;
void SieveOfEratosthenes(int num) {
   bool pno[num+1];
   memset(pno, true, sizeof(pno));
   for (int i = 2; (i*i <= num); i++) {
      if (pno[i] == true) {
         for (int j = i*2; j<= num; j += i)
         pno[j] = false;
      }
   }
   for (int i = 2; i <= num; i++)
   if (pno[i])
       { if ( 2*i > n) primes.pb(i);
          else {cc++; } }
}

void solve() {

  cin >> n; 
  int pos = upper_bound(all(primes), n) - primes.begin();
    
  trav(each, primes){
    cout << each << " ";
    if (each == 19){
      break;
    }
  }

  deb(pos);

  // ll siz = pos;

  // ll cnt = 0;
  // frr(i,siz-1, 0){
  //   if ( (primes[i]*2) <= n ){
  //     cnt =  i+1;
  //     break;
  //   }     
  // }

  if (cc >= 1)
    cout << 1 + (pos);
  else{
    cout << pos;
  }

  cc = 0;


}

signed main() {

    SieveOfEratosthenes(100);

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