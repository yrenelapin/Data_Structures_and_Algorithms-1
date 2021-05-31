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

bool isPalindrome(string str, ll i, ll j)
{
    while(i < j)
    {
      if ( str[i] != str[j] )
        return false; 
      i++;
      j--;
    }
    return true;
}

/*
This problem is a variation of Matrix Chain Multiplication problem. 
If the string is a palindrome, then we simply return 0. Else, like the Matrix Chain Multiplication problem,
we try making cuts at all possible places, recursively calculate the cost for each cut and return the minimum value
*/

ll MinPartPalindrome( ll i, ll j, string str, vvl &dp){

    // If string length is 1, It means its a palindrome already
    if (i == j){
        return 0;
    }

    if (dp[i][j] != -1){
        return dp[i][j];
    }

    ll res = INT_MAX;
    if (isPalindrome(str,i,j)){
        res = 0;
    }
    else{

        // Trying all the possible partitions similar to Matrix Chain Multiplciation
        fr(k, i, j-1){
             
            // Since we make 1 cut here, 1 + rem. two recursive calls. 
            res = min(res, MinPartPalindrome(i, k, str, dp) + MinPartPalindrome(k+1, j, str, dp) +  1);
        }

    }

    dp[i][j] = res;
    return res;
}


void solve() {
    string str; cin >> str; ll n = str.size();
    vvl dp(n+1, vl(n+1,-1)); 
    cout << MinPartPalindrome( 0, n-1, str, dp) << endl;  
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