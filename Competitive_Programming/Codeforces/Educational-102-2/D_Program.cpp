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

  ll n, m; cin >> n >> m; string s; cin >> s;
  vl main_array;
  ll x = 0;
  fr(i, 0, n-1){

      if (s[i] == '+'){
        x++;
      }
      else{
          x--;
      }
      
      main_array.pb(x);
  } 

  // Precomputing the mins & maxs from the beginning & ending.
  vvl mins( 2, vl(n, 0) ); // 0-> start, 1->end
  vvl maxs( 2, vl(n, 0) ); 

  mins[0][0] = main_array[0];
  fr(i, 1, n-1){
     mins[0][i] = min ( main_array[i],   mins[0][i-1] )  ;
  }

  mins[1][n-1] = main_array[n-1];
  frr(i, n-2, 0){
     mins[1][i] =  min ( main_array[i],   mins[1][i+1] );
  }

  maxs[0][0] = main_array[0];
  fr(i, 1, n-1){
     maxs[0][i] = max ( main_array[i],   maxs[0][i-1] );
  }

  maxs[1][n-1] = main_array[n-1];
  frr(i, n-2, 0){
     maxs[1][i] =  max ( main_array[i],   maxs[1][i+1] );
  }


  // Taking each query.
  ll d, b;
  fr(i,0,m-1) { 

              // Input
              cin >> d >> b; d--; b--; 

              // Since the values are contiguous in nature, 
              // If we know the minimum value (l) & maximum value (r) that occurs after removing given
              // operations in the specified range, we can know the number of unique values 
              // by just doing (r-l+1). We find the mins&maxs in suffixes & prefixes & then again take min& max among them to get required values.

              // Initialise to 0.
              ll l = 0; ll r = 0;

              // right index is with in limits.
              if (b < n-1){

                  if (d > 0){
                    
                    // Loss is the net effect of removing the given operations.
                    // This effect is shown on Suffixes.
                    ll loss = main_array[b] - main_array[d-1];
                    
                    // Minimum value obtained in the suffix
                    l = min(l, mins[1][b+1] - loss );

                    // Maximum value obtained in the suffix.
                    r = max(r, maxs[1][b+1] - loss );

                  }

                  else{
                    
                    // Note that here loss is main_array[b]-0
                    l =  min(l, mins[1][b+1] - main_array[b] - 0);
                    r =  max(r, maxs[1][b+1] - main_array[b] - 0);
                  
                  }
              }

              if ( d > 0 ){
                    // Note that, Prefixes Min/Max has no effect of removal.

                    // Minimum value obtained in the prefix.
                    l = min(l,mins[0][d-1]);

                    // Minimum value obtained in the prefix.
                    r = max(r,maxs[0][d-1]);
              }
                    
              // printing answer
              cout << (r-l+1) <<endl;
                    
            }

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
        //cout << "\n";
    }
    return 0;
}