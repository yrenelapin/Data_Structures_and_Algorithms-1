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

string s; 



ll countDecoding(string &s, ll n)
{    
    // If 1st element of string is 0, We cant decode it, since the numberings start from 1 till 26.
	if(s[0]=='0')
		return 0;

    // A table to store results of subproblems.
    //Sub Problem : Prefixes dp[i], No of ways to decode till (i-1)th index.
    vl dp( n+1, 0);

    // Empty string can be decoded in 1 way. (Assumption.)
	dp[0] = 1;

    // 1st element can be decoded in 1 way.
	dp[1] = 1;
    
    // Filling the table iteratively.
	for (int i = 2; i <= n; i++)
	{
		// If the last digit is not 0,
		// then it will add to the number of words during the usage of curr digit.
		if (s[i-1] != '0')
			dp[i] = dp[i-1];

        ll i_2 = s[i-2] - '0';
        ll i_1 = s[i-1] - '0';
        ll num = i_2*10 + i_1;

        // If last two digits form a valid number,  then no of ways to form till (i-1)th index is added (i-3)th index.
		if ( num <= 26  and num >= 1)
			dp[i] += dp[i-2];
	}

	return dp[n];
}


void solve() {
  cin >> s; ll n = s.size();
  cout << countDecoding(s, n);
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
