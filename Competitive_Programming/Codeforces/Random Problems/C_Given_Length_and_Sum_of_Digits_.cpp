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


 ll m,s;
string maximum_no(ll size, ll sum,  vector<vector<string>> &dp){

    if ( size <= 0 or sum < 0 ){ return "|"; }

    if (dp[size][sum] != "|" ){ return dp[size][sum]; }

    string res;

    if ( sum == 0 ){
        if (size >  1) { fr(i,1,size) res += "0"; }
        else {res = "0";}
    }

    else if ( size == 1 ){
        if (sum >= 10 ){ res = "|";} // Not Possible
        else{ res = to_string(sum); }
    }

    else{  // size >= 2 
        if (sum >= 9){

            string nxt;
            if (dp[size-1][sum-9] != "|" ){ nxt =  dp[size-1][sum-9] ; }
            else { nxt = maximum_no(size-1, sum-9, dp); } 

            if (nxt != "|" ) res = "9" + nxt;
            else { res = "9"; } 
        }
        else{

            string nxt;
            if (dp[size-1][0] != "|" ){ nxt =  dp[size-1][0] ; }
            else { nxt = maximum_no(size-1, 0, dp); } 

            if (nxt != "|" ) res = to_string(sum) + nxt;
            else {res = to_string(sum) ; } 
        }
    }

    return dp[size][sum] = res;
}

string minimum_no(ll size, ll sum, vector<vector<string>>  &dp){

     if ( size <= 0 or sum < 0 ){ return "|"; }

    if (dp[size][sum] != "|" ){ return dp[size][sum]; }

    string res;

    if ( sum == 0 ){
        if (size >  1) { fr(i,1,size) res += "0"; }
        else {res = "0";}
    }

    else if ( size == 1 ){
        if (sum >= 10 ){ res = "|";} // Not Possible
        else{ res = to_string(sum); }
    }

    else{  
            if (size == m){
                ll to_put = 1;
                fr(k,1,9){
                    if ( (sum-k) <=  ( 9*(size-1) ) ){
                        to_put = k; break;
                    }
                }
         
                string nxt;
                if (dp[size-1][sum-to_put] != "|"){ nxt =  dp[size-1][sum-to_put] ; }
                else { nxt = minimum_no(size-1, sum-to_put, dp); } 

                if (nxt != "|" ) res = to_string(to_put) + nxt;
                else {res = to_string(to_put) ; } 
            }
            else{
                ll to_put = 0;
                fr(k,0,9){
                    if ( (sum-k) <=  ( 9*(size-1) ) ){
                        to_put = k; break;
                    }
                }
                
        
                string nxt;
                if (dp[size-1][sum-to_put] != "|"){ nxt =  dp[size-1][sum-to_put] ; }
                else { nxt = minimum_no(size-1, sum-to_put, dp); } 

                if (nxt != "|" ) res = to_string(to_put) + nxt;
                else {res = to_string(to_put) ; } 
            }

    }

    return dp[size][sum] = res;
}

void solve() {
 cin >> m >> s;
  vector<vector<string>> dp(m+1, vector<string>(s+1,"|")); 
  vector<vector<string>> dp1(m+1, vector<string>(s+1,"|")); 

  string maxy =  maximum_no(m,s,dp); ll c= 0;

  trav(e, maxy){
      c += (e-'0'); 
  }
  
  bool leadingzeroes = false;
  if (m > 1){
      if (maxy[0] == '0' and maxy[1] == '0'){
          leadingzeroes = true;
      }
  }

  if (maxy == "|" or c !=  s or leadingzeroes){
      cout << -1 << " " << -1;
  }
  else{
      if ( maxy[m-1] != '0' ){ string miny = maxy; reverse(all(miny)); cout << miny << " " << maxy;}
      else { 
      string miny = minimum_no(m,s,dp1);  cout << miny << " " << maxy; }
  }

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