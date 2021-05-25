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
  ll n, k; string s;
  cin >> n >> k >> s;
  
  // To divide the string into half. 
  // If n is even, say 4, m = 2, then we need to use indices from 0,1. i.e. till m-1.
  // If n is odd,  say 5, m = 3, then we need to use indices from 0,1,2. i.e. till m-1.
  ll m = (n+1)/2;

  // This contains the count of number of strings that are lexic. smaller than half the input size string.
  ll res = 0;

  // To store the first half of string.
  string temp = "";
  
  // To calculate the number of strings lexicographically smaller than S′ (half input string),
  // we just need to convert the K-based number corresponding S′ to base 10. where K denotes the first k alphabets to be used.
  fr(i, 0, m-1){

      temp += s[i];

      // Getting the k-base Numbering for each character of string. 
      ll num = s[i] - 'a';
      
      // Calcualting power to convert to 10 - base numbering
      ll p =  pw(k, m-1-i); 
      
      // ( num*p ) corresponds to 10 - base numbering.
      // Notice that for larger numbers, when answer is asked after performing mod, during POWER calc also mod is to be used.
      res = ( res + (num*p) )% M;
   }

    // There is a caveat to look for, where if Half String being constructed is equal to S', we need to manually check if it is
    // lexicographically smaller or not. 

    // Constructing palindrome from 1st half.
    fr(i,m,n-1){
        temp.pb(s[n-i-1]);
    }

    if (temp < s){
        res = (res + 1)% M;
    }

    cout << res;
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}