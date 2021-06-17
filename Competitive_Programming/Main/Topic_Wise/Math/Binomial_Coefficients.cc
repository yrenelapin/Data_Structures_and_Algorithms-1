// Quick calculation of nCk
// Time complexity: O(1) per query, O(n) precomputation
// Precompute all the factorials and Modular inverse to calculate nCk = n!/(k!(n-k)!)
// Problem link: https://cses.fi/problemset/task/1079

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long                                  
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(int (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(int (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<pi>	vpi;
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef priority_queue<int> prq;                          
const int M = 1e9 + 7;
const int INF = 1e18;
//-------------------------------------------------------- DebugHelp--------------------------------------------------
vector<string> vec_splitter(string s) {s += ','; vector<string> res; while(!s.empty()) { res.push_back(s.substr(0, s.find(','))); s = s.substr(s.find(',') + 1);} return res;}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx,  __attribute__ ((unused)) int LINE_NUM) { cout << endl; } 
template <typename Head, typename... Tail> void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) { if(idx > 0) cout << ", "; else cout << "Line(" << LINE_NUM << ") ";stringstream ss; ss << H;cout << args[idx] << " = " << ss.str();debug_out(args, idx + 1, LINE_NUM, T...); }
#define dbg(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
//-------------------------------------------------------- OperatorOverload --------------------------------------------------
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   
template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) 
{ os << "[ "; for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const set<T>& v) 
{ os << "[ "; for (auto it : v) { os << it; if (it != *v.rbegin()) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const multiset<T>& v) 
{ os << "[ "; for (auto it : v) os << it << ", "; os << " ]\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const map<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const multimap<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const pair<T, S>& v) 
{ os << "("; os << v.first << ", " << v.second << ")"; return os; }
template <typename T> ostream& operator<< (ostream& os, priority_queue<T> p)
{ os << "[ "; while(!p.empty()){ os << p.top() << " ,"; p.pop(); } os << " ]\n"; return os; }
// ----------------------------------------------------------------------------------------------------------------------//

const int MAX_N = 1e6 + 1;

int qexp(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int fact[MAX_N], invf[MAX_N];

void precompute() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = fact[i - 1] * i % M;
        invf[i] = qexp(fact[i], M - 2, M); // Fermat's little theorem
    }
}

int nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invf[k] % M * invf[n - k] % M;

    // if there are only a few queries, then don't need to precompute invf[] => faster
    // return fact[n] * qexp(fact[k], M - 2, M) % M * qexp(fact[n - k], M - 2, M) % M;
}

// A trick to calculate large factorial without overflowing is to take log at every step when precompute and take exponential when calculating
// Don't need invf[] now because it is the same as negative log of fact
double log_fact[MAX_N];
void precompute_log() {
    log_fact[0] = 0.0; 
    for (int i = 1; i < MAX_N; i++)
        log_fact[i] = log_fact[i - 1] + log(i); 
}

int log_nCk(int n, int k) { 
    if (k < 0 || k > n) return 0;
    return exp(log_fact[n] - log_fact[n - k] - log_fact[k]); 
}

// Iterative way 
int ncr (int n,int k){ 
    int ans = 1; 
    if (k>n-k) {k=n-k;} 
    fr(i,1,k)
        {ans*=(n-i+1); 
        ans/=i; }
    return ans; 
}

// Computing ( nCr mod p ) where p is a prime number greater than n.
int modpow(int a, int p = M-2, int MOD = M )   { int result = 1; while (p > 0) { if (p & 1) { result = a * result % MOD; } a = a * a % MOD; p >>= 1; } return result; }
int modinv(int n, int p) { return modpow(n, p - 2, p);}
int ncrModPFermat(int n,int r, int p) {
        if (r == 0)
            return 1;
        int fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % p;
        return (fac[n] * modinv(fac[r], p) % p * modinv(fac[n - r], p) % p) % p;
}

void solve() {
    int n, k; cin >> n >> k;

    cout << nCk(n, k) << "\n";

    cout << ncr(n,k)  << "\n";

    cout << ncrModPFermat(6,2,13)  << "\n";
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    //cin >>  t; 
    
    precompute();   // <-- Notice this.
    
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
