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

  ll n, k; cin >> n >> k;
  string s; cin >> s; 
  vl v(k); 
  fr(i,0,k-1) { cin >> v[i]; }

   ll act_dis = 0;
   fr(j,0,n-2){
          if (s[j] == s[j+1]){
            act_dis += 2;
          }
          else{
            act_dis++;
          }
    }



  fr(i,0,k-1){

      if ( s[v[i]-1] == '0' ) {
       

              // Not 1st & last.
              if ( ((v[i]-1) != 0) and ((v[i]-1) != n-1) ){

                  ll actual_contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

                  if ( s[v[i]-1] == s[v[i]]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

                  // Update
                  s[v[i]-1] = '1';

                  ll contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  if ( s[v[i]-1] == s[v[i]]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  act_dis -= (actual_contr - contr);

              }
              else if ( (v[i]-1) == 0 ) { 
                  
                  ll actual_contr = 0;
                  if ( s[v[i]-1] == s[v[i]]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

                  // Update
                  s[v[i]-1] = '1';

                  ll contr = 0;

                  if ( s[v[i]-1] == s[v[i]]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  act_dis -= (actual_contr - contr);
              }
              else{  // Last element

                  ll actual_contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

              
                  // Update
                  s[v[i]-1] = '1';

                  ll contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  act_dis -= (actual_contr - contr);


              }

    
      }
      else {

        // Not 1st & last.
              if ( ((v[i]-1) != 0) and ((v[i]-1) != n-1) ){

                  ll actual_contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

                  if ( s[v[i]-1] == s[v[i]]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

                  // Update
                  s[v[i]-1] = '0';

                  ll contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  if ( s[v[i]-1] == s[v[i]]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  act_dis -= (actual_contr - contr);

              }
              else if ( (v[i]-1) == 0 ) { 
                  
                  ll actual_contr = 0;
                  if ( s[v[i]-1] == s[v[i]]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

                  // Update
                  s[v[i]-1] = '0';

                  ll contr = 0;

                  if ( s[v[i]-1] == s[v[i]]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  act_dis -= (actual_contr - contr);
              }
              else{  // Last element

                  ll actual_contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    actual_contr += 2;
                  }
                  else{
                    actual_contr += 1;
                  }

              
                  // Update
                  s[v[i]-1] = '0';

                  ll contr = 0;

                  if ( s[v[i]-2] == s[v[i]-1]){
                    contr += 2;
                  }
                  else{
                    contr += 1;
                  }

                  act_dis -= (actual_contr - contr);


              }




      }

      



    cout << act_dis << endl;

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