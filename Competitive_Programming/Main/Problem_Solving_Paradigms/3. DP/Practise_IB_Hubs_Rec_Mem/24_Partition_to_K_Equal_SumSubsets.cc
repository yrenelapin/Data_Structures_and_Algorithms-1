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
// Ref : https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/

// Notice that, DP is not applicable since the Sub Problems one can think off hardly has OPTIMAL SUBSTRUCTURE ( Think again ).
// So, Recursive Backtracking is used below:

bool IsKPartitionsPossible(ll curInx, ll ToInclude, vl &v, vl &visited, vl &subsets, ll subset_sum, ll k,  ll n){

    // If a partition is formed with required sum
    if (subsets[curInx] == subset_sum){

        // If k-1 partitons are already made with required sum, It means we partitioned into `k` parts.
        if (curInx == k-2){
          return true;
        }
        
        // Go for next partition
        return IsKPartitionsPossible(curInx+1, n-1, v, visited, subsets, subset_sum, k, n);
        
    }
    

    // Include the elements into the partition & perform backtracking.
    frr(i, ToInclude, 0){

      if (visited[i]){
        continue;
      }

      ll temp = subsets[curInx] + v[i];
      
      if (temp <= subset_sum){
        
        // Include
        subsets[curInx] += v[i];
        visited[i] = 1;

        // Recurse
        bool nxt = IsKPartitionsPossible(curInx, i-1, v, visited, subsets, subset_sum, k, n);

        // Exclude
        subsets[curInx] -= v[i];
        visited[i] = 0;
  
        if (nxt){
          return true;
        }

      }
    }
    return false;
}


void solve() {
  ll n, k; cin >> n >> k;
  vl v(n); ll total = 0; 
  fr(i,0,n-1) { cin >> v[i]; total += v[i] ; }

  // Base Cases :
  if ( k == 1){  cout << "True"; return;} // Entire array is the req. answer
  if ( n < k ){  cout << "False"; return;} // Cant make partitions.
  if ( total % k != 0) { cout << "False"; return;}
  ll subset_sum =  (total/k );

  vl subsets(k,0); vl visited(n,0); 
  subsets[0] = v[n-1]; visited[n-1] = 1;

  ( IsKPartitionsPossible(0, n-1, v, visited, subsets, subset_sum, k, n) == 1 )? cout << "True" : cout << "False";
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