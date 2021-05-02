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

void solve() {
  ll n,l,r;
  cin >> n >> l >> r;

  vl c(n);
  multiset<ll> left, right;

  unordered_map<ll,ll> left_freq, right_freq;

  fr(i,0,n-1)  { cin >> c[i];
                  if (i+1 <= l){
                      left.insert(c[i]);
                      left_freq[c[i]]++;
                  } 
                  else{
                      right.insert(c[i]);
                      right_freq[c[i]]++;
                  }
                }
  
  // With decreasing sort order.
  multimap<ll, ll, greater<ll> > left_freq_sort, right_freq_sort;
  
  trav(each, left_freq){
      left_freq_sort.insert({each.se, each.fi});
  }

  trav(each, right_freq){
      right_freq_sort.insert({each.se, each.fi});
  }


  ll result = abs(l-r)/2 ;
   
   // l : 6,5,4,3,2    r : 1 
  if (l >= r){

      while ( left.size() != right.size()){

        // Take one element with max freq.
        ll to_remove = left_freq_sort.begin()->second;
        left_freq[to_remove]--;
         
        left.erase(left.lower_bound(to_remove));  // This step is slow
 
        left_freq_sort.erase(left_freq_sort.begin());

        right.insert(to_remove);
        right_freq[to_remove]++;
      }

  }
  else{

    while ( left.size() != right.size()){

        // Take one element with max freq.
        ll to_remove = right_freq_sort.begin()->second;
        right_freq[to_remove]--;
        
        right.erase(right.lower_bound(to_remove)); // This step is slow


        right_freq_sort.erase(right_freq_sort.begin());

        left.insert(to_remove);  

        left_freq[to_remove]++;
      }


  }


  ll count1 = 0 ;
  trav(each, left){
      if (right_freq[each] <= 0){
          count1++;
      }
  }

  ll count2 = 0 ;
  trav(each, right){
      if (left_freq[each] <= 0){
          count2++;
      }
  }

   result += max(count1, count2);
   cout << result;

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