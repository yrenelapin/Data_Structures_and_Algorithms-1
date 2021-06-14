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
    ll n, l, r; cin >> n >> l >> r;
    vl v(n); fr(i,0,n-1) cin >> v[i];
    sort(all(v));
    ll ans = 0;
    // Basically, first we are finding all possible pairs (i,j) such that given cond holds,  and ( i != j)
    for (int i = 0; i < n; i++) {

        // Binary search for elements whose sum is <= r by finding number of elements whose values are <= r-v[i]
        ans += upper_bound(all(v), r - v[i]) - v.begin();

        // Binary search for elements whose sum is <= l-1 by finding number of elements whose values are <= l-1-v[i]
        ans -= upper_bound(all(v), l - 1- v[i]) - v.begin();

        // While performing binary search for the numbers that fulfill the condition of a[i]+a[j]>=l && a[i]+a[j]<=r,
        // it may occur that the number itself also fulfills this condition .
        // So to resolve this we check if the number itself fulfills the condition ( a[i]+a[i]=2*a[i] ) and if it is so we remove one pair.
    
        if (l <= 2 * v[i] && 2 * v[i] <= r) { 
            // Here we have ( i = j ), which we dont want to count.
            ans--;
        }
    }

    // This is done because in the question it is mentioned that i<j i.e i is always less than j ,
    // however in our code we are unable to check for this condition so for values of i>j also the pairs are calculated. 
    // For given n, # pairs with i < j and i >j are equal. Anyhow we removed i == j cases
    // This means that all pairs are counted twice. To remedy this we divide our final ans by 2.
    cout << ans / 2 ;
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