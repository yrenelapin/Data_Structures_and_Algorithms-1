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

    string s; cin >> s; ll n = s.size();
    ll ans = 0;

    // To store the maximum index.
    vl invariant(2,-1);

    fr(i,0,n-1){

        ll ch = s[i] - '0';

        // We dont care abt the '?' becoz we can anyhow make its value such that Invariant is same.
        if ( ch == 1 or ch == 0){

            // Calulate the xor & store the index.
            invariant[ (i%2)^(ch) ] = i;
        }

        // The quantities invariant[0] the maximum position untill which invariant is 0.Similarly invariant[1].
        // We need to take the one that ends first & take the elements from the next index till i which is a Beautiful substring & hence
        // all its substrings are also beautiful.

        // At each step, We are calculating the number of substrings that end at the index i.
        // Note that number of sustrings that end at index i, is equal to string length (i+1) . (0 based indexing) 
        // Hence total substrings are the summation over above quantity for i from 0 to n-1.
  
        ll mn = min(invariant[0], invariant[1]);
        
        ans += (i-mn);
    }   

    cout << ans;
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

// Ref : https://www.youtube.com/watch?v=P08WLISI1NY&t=2015s