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

// 10^18 is the maximum number, It requires just 19 digits. --> say 20  is choosen
// 10 possible digits. 
// Other two are boolean.
ll dp[20][10][2][2];

/* Args:
  number         --> Actual Number which is the upper bound i.e. x when solving [0,x]
  n              --> Left most digit which we are currently filling & counting the ways.
                     So for a Number, MSB has value Number.size(). LSB has 1.
  x              --> Value filled at the previous digit. (for n-1 th digit)
  leading_zeroes --> Is there a possibility of filling Leading Zeroes at the current position?
  tight          --> Is there a bound on the number of digits that can be filled at the current position? 
*/
ll count_nums(string number, ll n, ll x, bool leading_zeroes, bool tight ){

  // Empty Number
  if (n == 0){
      return 1;
  }

  // x == -1 only in the first digit (MSB), Anyhow that is to be computed, so we used ( x != -1)
  // Moreover in general problems, lookup with dp[-1] causes Segmenatation fault!
  if (x != -1 and dp[n][x][leading_zeroes][tight] != -1){
    return dp[n][x][leading_zeroes][tight];
  }

  // Defining the range for the values possible at the current digit.
  ll lb = 0;
  // If `tight` is 1, take the value from the actual number as the upper bound, else 9.
  ll ub = ( tight ? ( number[number.size()-n] - '0') : 9 );

  ll ans = 0;

  // Trying all the possibilites of the current digit & counting.
  fr(dig,lb,ub){

    // If the previous digit & current digit are same & there is no possibility of leading zeroes, It means that
    // this case is to be avoided since there are same adjacent elements.
    if (dig == x and !(leading_zeroes)){
      continue;
    }
     ans += ( count_nums(number, n-1, dig,   ( leading_zeroes & (dig == 0) ), tight & (dig == ub)    ) );
  }

  return dp[n][x][leading_zeroes][tight] =ans;
}

void solve() {
  ll a,b; cin >> a >> b; 

  // Standard trick in Digit DP is to split the Interval [a,b] into [0,b] & [0,a-1]. Solve the problem for [0,x] using which we can
  // solve the other two & then subtract the results of [0, b] & [0, a-1] to get results accordingly.
  string A = to_string(a-1);
  string B = to_string(b);
  
  memset(dp,-1, sizeof(dp));

  // Args: Number, No of Digits, Previous digit is (-1), Leading Zeroes possible(1),  Tight(1)
  ll ans1 = count_nums(B,B.size(), -1,1,1);

  memset(dp,-1, sizeof(dp));
  ll ans2 = count_nums(A, A.size(),-1,1,1);

  cout << ans1 - ans2;
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

// Ref: https://youtu.be/lD_irvBkeOk