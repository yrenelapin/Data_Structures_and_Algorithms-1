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
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;


/*
Check the Problem Statement here : https://codeforces.com/contest/1486/problem/C2
*/

map<pi, int> qans;
 
int query(int l,int r){

	// To avoid repeated queries, we check in the map where we have stored earlier.
	if(qans.count({l,r})){
		return qans[{l,r}];
	}

	// If its an invalid query.
	if(l == r){
		return -1;
	}

	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;

	// Store in Map & return the answer.
	return qans[{l,r}] = ans;
}

void answer(int x){
	cout << "! " << x << endl;
}
 
void solve(){
	int n;
	cin >> n;
	
	// First query on entire length.
	int smx = query(1,n);
	int ans;

	// Check if second max in [1,smx] is same as smx, which means `max value` is in [1, smx-1] 
	if(smx == query(1,smx)){
		// [1 to smx]

		// Doing binary search to find.
		int L = 1, U = smx - 1;
		while(L <= U){
			int m = (L + U) / 2;

			// If this happens, It means that, `Max Value` is either m or it lies in [ m+1, smx-1]
			if(query(m,smx) == smx){
				ans = m; 
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
	}
	else{
		// [smx to r]
		int L = smx + 1, U = n;
		while(L <= U){
			int m = (L + U) / 2;

			// If this happens, It means that, `Max Value` is either m or it lies in [smx+1, m-1]
			if(query(smx,m) == smx){
				ans = m;
				U = m - 1;
			}
			else{
				L = m + 1;
			}
		}
	}
	answer(ans);
}
int main() {
    fastIO;
    int t = 1;
    fr(T,1,t){
        solve();
    }
    return 0;
}