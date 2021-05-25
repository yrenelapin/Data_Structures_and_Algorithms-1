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
const long long INF = 1e18;


/*
* Function return all possible combinations of k elements from N-size inputVector.
* The result is returned as a vector of k-long vectors containing all combinations.
*/
template<typename T> std::vector<std::vector<T>> getAllCombinations(const std::vector<T>& inputVector, int k)
{
    std::vector<std::vector<T>> combinations;
    std::vector<int> selector(inputVector.size());
    std::fill(selector.begin(), selector.begin() + k, 1);

    do {
        std::vector<int> selectedIds;
        std::vector<T> selectedVectorElements;
        for (int i = 0; i < inputVector.size(); i++) {
            if (selector[i]) {
                selectedIds.push_back(i);
            }
        }
        for (auto& id : selectedIds) {
            selectedVectorElements.push_back(inputVector[id]);
        }
        combinations.push_back(selectedVectorElements);
    } while (std::prev_permutation(selector.begin(), selector.end()));

    return combinations;
}



bool win( int ele, vi chosen, vi v){
  
  multimap<int,int> m ;

  trav(e, v){
    m.insert({ abs(e - ele), e });
  }

  auto min_dis = m.begin()->first;

  if (  ( abs(ele- chosen[0]) < min_dis ) or   ( abs(ele- chosen[1]) < min_dis ) ){
    return true;
  }
  else{
    return false;
  }

}



void solve() {
  int n, k ;
  cin >> n >> k;
  vi v(n);
  fr(i,0,n-1) cin >> v[i];
  
  vi rem;
  fr(i, 1, k){
    // Not present in v.
    if( find( all(v), i ) == v.end() ) {
      rem.pb(i);
    }
  }

  int no_rem = rem.size();





  if (no_rem >= 2){
       vi chosen;

      auto res = getAllCombinations(rem, 2);

      int maxy_prob = INT_MIN;
      trav(each, res){
          chosen.pb(each[0]);
          chosen.pb(each[1]);
          int no_of_wins = 0;

          trav(ele, rem){            
              if ( win(ele, chosen, v) ){
                no_of_wins++;
              }
          }

          maxy_prob = max(maxy_prob, no_of_wins);
          chosen.clear();
      }
        
      decimal(10);  
      cout << (double)maxy_prob/(k) ;




  }
  else if (no_rem == 1){

      vi chosen;
      chosen.pb(rem[0]);
      chosen.pb(rem[0]);

      int no_of_wins = 0;

      // deb2(chosen[0], chosen[1]);
      trav(ele, rem){

          
          if ( win(ele, chosen, v) ){
            no_of_wins++;
          }

          //deb2(ele, win(ele, chosen, v));
      }

      decimal(10);  
      cout << (double)no_of_wins/(k) ;

    
  }
  else{
    decimal(10);  
    cout << 0.0 ;
  }



}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}