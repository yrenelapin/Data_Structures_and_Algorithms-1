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


// Input Data
ll n = 8;
// 1st element is not required.
vl v = {1,3,4,8,6,1,4,2};

vl prefix_sum(n);
vl tree(n+1);


// O(n)
void build_prefix(){

    for (int i = 0; i < v.size() ; i++){
        if (i == 0){
            prefix_sum[0] = v[0];
        }
        else prefix_sum[i] = v[i] + prefix_sum[i-1];
    }

}


int query(int start_index, int end_index){

    if (start_index == 0){
        return prefix_sum[end_index];
    }

    if (start_index == end_index){
        return v[start_index];
    }

    return (prefix_sum[end_index] -  prefix_sum[start_index-1]) ;
}


// O(n)
void binary_indexed_tree(){
    fr(k,1,n){
        ll p_k = k & (-k);
        ll a =  k - p_k + 1;
        ll b =  k;

        // Each position k contains the sum of values in a range of the original array whose length is p(k) and that ends at position k. 
        tree[k] = query(a-1,b-1);
    }
}


/* 
Binary Indexed Trees supports two O(logn) time operations on an array:
processing a range sum query and updating a value. */


//  Calculates value of sum_q(1,k)
ll sum(ll k) {
    ll s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}


// Function increases the array value at position k by x (x can bepositive or negative):
void add(ll k, ll x) {

    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}


void solve() {

   build_prefix();
    
    cout << "Given Array \t\t";
    tra(i,v){
        cout << i << " ";
    }
    cout << endl;

    cout << "Prefix Sum Array \t";
    tra(i,prefix_sum){
        cout << i << " ";
    }
    cout << endl;

   binary_indexed_tree();

   cout << "Binary Indexed Tree \t"; 
   tra(i,tree){
       cout << i << " ";
   }
    cout << endl;

    deb(sum(5));
    
    // if (a > 1) sum_q(a,b) = sumq(b)−sum(a−1).
    // else sum_q(a,b) = sum(b);

    // To find sum_q(2,4);

    deb( sum(4)- sum(1) ) ;
    add(3,1);
    deb(sum(5));
    add(3,4);
    deb(sum(5));
}


signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    // cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}