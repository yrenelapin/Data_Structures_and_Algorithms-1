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
  string s,t; cin >> s >> t;
  vector<string> s_pos, t_pos; 
  ll s_len = s.size(); ll t_len = t.size(); ll pro =  s_len*t_len;
    
    //deb(pro);

  string temp_s = s; 
  while (temp_s.size() <= pro){
      s_pos.pb(temp_s);
      temp_s += s;
  } 

  string tempt = t; 
  while (tempt.size() <= pro){
      t_pos.pb(tempt);
      tempt += t;
  } 
    
//    trav(s, s_pos){
//        deb(s);
//    } 

//    trav(t, t_pos){
//        deb(t);
//    } 

  ll ss = s_pos.size()-1; ll flag1 = 0; string ans1 = "?";
  fr(i, 0, ss){
      if ( find (all(t_pos), s_pos[i]) != t_pos.end() ){
          flag1 = 1;
          ans1 = s_pos[i];
          break;
      }
  }

  ll tt = t_pos.size()-1; ll flag2 = 0; string ans2 = "?";
  fr(i, 0, tt){
      if ( find (all(s_pos), t_pos[i]) != s_pos.end() ){
          flag2 = 1;
          ans2 = t_pos[i];
          break;
      }
  }

  if (ans1 == "?"  and ans2 != "?"){
      cout << ans2;
  }
  if (ans2 == "?"  and ans1 != "?"){
      cout << ans1;
  }
  else if (ans2 == "?"  and ans1 == "?"){
      cout << -1;
  }
  else{
      if (ans1.size() <= ans2.size()){
          cout << ans1;
      }
      else{
          cout << ans2;
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
        cout << "\n";
    }
    return 0;
}