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


void solve() {
    ll n;
    cin >> n;
    vl a(n+2);
    ll sum = 0;
    fr(i,0,n+1) { cin >> a[i]; sum+= a[i]; }

    unordered_multiset<ll> v(a.begin(), a.end());

    // We need to traverse the main array, not the multiset, becoz we are updating the multiset in process.
    tra(x, a){

        v.erase(v.find(x));
        sum -= x;

        // Checking if `x` is the random element inserted in b.
        if ( (sum %2 == 0) and sum <= 2e9 and v.find(sum/2) != v.end() ){
                
                // If yes, Just remove the sum element & print.
                v.erase(v.find(sum/2));

                trav(i, v){
                cout << i << " ";
                }

                return;

        }

        // Else, we just place it again & move to next element.
        sum += x;
        v.insert(x);


    }

    cout << -1;
    return;
}

int main() {
    fastIO;
    int t = 1;
    cin >>  t; // Comment if only 1 testcase.
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << endl;
    }
    return 0;
}