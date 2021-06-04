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

// Kadanes Algorithm
ll max_subarray_sum(vl array, ll n){

    ll sum = 0; ll max_sum = 0;
    for (ll i = 0; i <n; i++){
        sum =  max(array[i], sum + array[i]);
        max_sum = max(sum, max_sum);
    }
    
    if (max_sum == 0){
        // This condition is helpful if We assume that an empty subarray is NOT allowed, 
        // so the maximum subarray sum is NOT always at least 0. 
        // It can be negative too.
        return *max_element(all(array));
    }
    else { return max_sum ; }
}

int main()
{  
    ll n; cin >> n;
    vl array(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << max_subarray_sum(array, n) << endl;   
}


// This is the actual Kadanes Algorithm. We assume that an empty subarray is allowed, so the maximum subarray sum is always at least 0.
//  If this is not the case, This O(n) algorithm Fails.

// int main(){

//     int array[8] = {-1, 2, 4, -3, 5, 2, -5, 2};
//     int sum = 0; int max_sum = 0;
//     for (int i = 0; i <8; i++){
//         sum =  max(array[i], sum + array[i]);
//         max_sum = max(sum, max_sum);
//     }

//     cout << max_sum << "\n";
    
// }
