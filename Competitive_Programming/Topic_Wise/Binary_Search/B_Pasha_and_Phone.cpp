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

void solve(){
	ll n, k ;
	cin >> n >> k;
    vl a(n/k), b(n/k);

    fr(i,0,(n/k)-1){
        cin >> a[i];
    }
	fr(i,0,(n/k)-1){
        cin >> b[i];
    }

 
    ll count = 1;
    ll maxy =  pow(10, k)-1;

    fr(i,0,(n/k)-1){    
        
        // All are zeroes
        ll curr_count = 1; 

        // Including the ones % by ai
        curr_count += (maxy/a[i])%mod;
     
        // Removing the ones that start with bi
        ll copy_curr = curr_count;
        fr(j, 0, copy_curr-1){

            string str = to_string(a[i]*j);
            ll first_digit;  
            if  (str.size() == 1){

                if (k > 1){
                       first_digit = 0;
                }
                else{
                    first_digit = stoi(str);
                }
             
            }
            else{
                first_digit =  ( str[0]- '0');
            }
            
            if ( first_digit == b[i] ){
                curr_count--;
            }
        }
        count *= ( curr_count % mod );
    }

    cout << count % mod;

}

int main() {
    fastIO;
    int t = 1;
    fr(T,1,t){
        solve();
        //cout << "\n";
    }
    return 0;
}