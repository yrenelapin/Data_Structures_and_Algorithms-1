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
    
  ll n, m ; cin >> n >> m;
  char grid[n][m]; 
  fr(i,0,n-1) { 
      fr(j,0,m-1) {cin >> grid[i][j]; 
  }}

    char ans1[n][m];

    fr(i,0,n-1){
        
        // Even
        if (i%2 == 0){
            fr(j,0,m-1){ 
                if (j%2 == 0){
                    ans1[i][j] = 'R';
                }
                else{
                    ans1[i][j] = 'W';
                }

            }
        }

        // Odd
        if (i%2 == 1){
            fr(j,0,m-1){ 
                if (j%2 == 0){
                    ans1[i][j] = 'W';
                }
                else{
                    ans1[i][j] = 'R';
                }

            }
        }
    }
       
       // Check if ans1 matches. 
        ll one = 1;
        fr(i,0,n-1){
            fr(j,0,m-1){ 
                //cout << ans1[i][j] << " ";
                if (grid[i][j] != '.'){
                    if (grid[i][j] != ans1[i][j]){
                        one = 0;
                        break;
                    }
                }

            }
        }

 
   // Fails
  if (one == 0){
    
                    char ans2[n][m];

                    fr(i,0,n-1){
                        
                        // Even
                        if (i%2 == 0){
                            fr(j,0,m-1){ 
                                if (j%2 == 0){
                                    ans2[i][j] = 'W';
                                }
                                else{
                                    ans2[i][j] = 'R';
                                }

                            }
                        }

                        // Odd
                        if (i%2 == 1){
                            fr(j,0,m-1){ 
                                if (j%2 == 0){
                                    ans2[i][j] = 'R';
                                }
                                else{
                                    ans2[i][j] = 'W';
                                }

                            }
                        }
                    }


                        // Check if ans2 matches. 
                        ll two = 1;
                        fr(i,0,n-1){
                            fr(j,0,m-1){ 
                                //cout << ans1[i][j] << " ";
                                if (grid[i][j] != '.'){
                                    if (grid[i][j] != ans2[i][j]){
                                        two = 0;
                                        break;
                                    }
                                }

                            }
                        }
                    
                    if (two == 1){
                        cout << "YES\n";
                        fr(i,0,n-1){
                            fr(j,0,m-1){ 
                                cout << ans2[i][j] ;

                            }
                            cout << endl;
                            }
                    }
                    else{
                        cout << "NO\n";
                    }
        }
        else{

                // Print ans1
                cout << "YES\n";
                fr(i,0,n-1){
                    fr(j,0,m-1){ 
                        cout << ans1[i][j] ;

                    }
                    cout << endl;
                    }

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