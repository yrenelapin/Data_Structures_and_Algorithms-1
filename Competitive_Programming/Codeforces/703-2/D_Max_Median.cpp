#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long                                   // Comment it out if default `int` is req. 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(int (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(int (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
using namespace std;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<pi>	vpi;
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef priority_queue<int> prq;                          
const int M = 1e9 + 7;
const int INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   

void solve() {

  int n,k; cin >> n >> k;
  // int dp[n][n]; memset(dp,-1, sizeof(dp));
  vi v(n); fr(i,0,n-1) { cin >> v[i]; }
  
  // Since the elements of the vector lie  between 1-n we can directly do Binary search using numbers instead of indices.
  int l = 1, r = n  ; int ans = 0;
  while ( l <= r ){

      int m = (l+r)/2;
      
      vi b(n);
      fr(i,0,n-1){
          if (v[i] < m){
              b[i] = -1;
          }
          else{
              b[i] = 1; 
          }
      }

      // Building the prefix sum array.
      fr(i,1,n-1){
          b[i] += b[i-1];
      }
     
    //   deb(m);
    //   trav(e,b){
    //       cout << e << " ";
    //   }cout << endl;

     // Since we replaced the values as -1,+1, the `m` as median is possible if there is a subarray of size atleast k with positive sum.
     // So, we need ( b[i] - b[j-1] >  0  and  i-j+1 >= k ). So for these indices, lets find the max value of b[i]-b[j-1].

     // Initially, our i = k-1, j is not defined, b[j] is taken 0. This is a subarray starting from beginning & of length k. 
     int mx = b[k - 1];  
     int mn = 0;          

     fr(i, k, n-1) {
            mn = min(mn, b[i - k]);   // Tracking the minimum value of b[j-1] for all possible j value.
            mx = max(mx, b[i] - mn);  // Tracking the max value of b[i]-b[j-1]
     }
    
    // The Maximum subarray sum of length atleast k is > 0, Which means that `m` can be a median, or the actual answer is atleast `m`.
    // So, now we move to the right part.
    if (mx > 0) {
        ans = m;
        l = m+1;
    } 
    else {
        r = m-1;
    }

  }

  cout << ans;
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
