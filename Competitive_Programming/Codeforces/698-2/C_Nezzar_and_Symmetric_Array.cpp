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


void solve(){
  
  ll n;
  cin>>n;

  ll a[2*n];
  for(ll i =0; i<2*n; i++){

    cin>>a[i];
    //deb2(i,a[i]);

  }

  if (n ==1){
    if (a[0] == a[1] and a[0]%2 == 0){
      cout << "YES\n"; return;
    }
  }

  map<ll,ll> mp;

  for(ll i =0; i<2*n; i++){
    mp[a[i]]++;
  }
  
  for(auto i : mp){

    if(i.first%2 ==1 || i.second !=2){
   
      cout<<"NO"<<endl;
      return;
    }
  }

  vector<int> v;
  for(auto i : mp){    
    // We know if we divide distances by 2, we get equations which are sums of some elements.
    ll val = i.first/2;
    ll fre = i.second/2;

    for(ll j =0; j<fre; j++){
      v.push_back(val);
    }
  }
 
  sort(v.begin(),v.end());
  set<ll> s;

  ll sum =0;
  bool flag = true;
  for(ll j = n-1; j>=0; j--){

    ll y = (v[j]-sum)/(j+1);      
    // Solving the equations (starting from last one.). To get more clarity write equations on paper.
    //`y` represents the elements of the array being formed. 

    ll rem = (v[j]-sum)%(j+1);
    
    if(s.find(y)!=s.end() || rem!=0 || y<=0){   
   cout << "h";
    // All elements should be unique too and All elements should be integers only. So, reminder should be 0.
      cout<<"NO"<<endl;
      return;
    }
    else {

      s.insert(y);
      sum+=y; // To solve the next equation.
    }
  }

  cout<<"YES"<<endl;
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