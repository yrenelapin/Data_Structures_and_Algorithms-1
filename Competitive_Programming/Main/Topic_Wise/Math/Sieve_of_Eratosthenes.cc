// Generate all primes <= n
// Time complexity: O(nlog(logn))
// Problem link: https://dunjudge.me/analysis/problems/271/

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

// Check if n is a prime in O(sqrt(n))
bool prime_check(int n) { 
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Generate the primes <= n in O(nlog(logn))
vector<int> sieve(int n) {
    vector<int> primes, is_prime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i + i; j <= n; j += i)
                is_prime[j] = 0;
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}

// ---------------------------------------------------------------------------------------------
// Modified sieve to make enable prime factorization in log(n)
// Instead of just storing whether a number is prime, we will store its smallest prime factor greater than 1
const int MAX = 1e6 + 5;
vector<int> spf(MAX); // stores smallest prime factor for every number

// Calculating SPF (Smallest Prime Factor) for every number till MAX & also returns Primes. Time Complexity : O(nloglogn) 
vector<int> modified_sieve(int n) {
    for (int i = 1; i <= n; i++)
        spf[i] = i;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) 
        if (spf[i] == i)
            for (int j = i + i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    for (int i = 2; i <= n; i++)
        if (spf[i] == i)
            primes.push_back(i);
    return primes;
}

// Returns the vector containing the prime factors of x using precomputed SPF.
vector<int> factorize(int x) {
    vector<int> res;
    while (x > 1) {
        res.push_back(spf[x]);
        x /= spf[x];
    }
    return res;
}

// ---------------------------------------------------------------------------------------------

// Prime Factors in O(sqrt(n))
vi prime_factors(int n){
    vi res;
    for(int i = 2; i*i <= n; i++){
        while (n % i == 0){
            res.pb(i);
            n /= i;  
        }
    }
    if (n > 1) res.pb(n);
    return res;
}

// ---------------------------------------------------------------------------------------------
// A different type of sieve but with same functionality.
vi sieve_erato(int n){
    /*sieve[k]  = 0  -> k is prime
      sieve[k] != 0  -> k is not a prime & one of its prime factors is sieve[k].*/
    vi sieve(n+1);
    fr(i,2,n){
        if (sieve[i]) continue;
        for(int j = 2*i; j <= n; j+=i ){
            sieve[j] = i;
        }
    }
    return sieve;
}


void solve() { 

    // Generate the primes <= 20
    vi check1 = sieve(20);
    cout << check1;

    // Prime Factors in O(log(n))
    vi pre_comp = modified_sieve(20);
    vi check2 = factorize(20);
    cout << check2;
    
    // Prime Factors in O(sqrt(n))
    vi check3 = prime_factors(20);
    cout << check3;
    
    // print the n-th prime (n <= 1e4)
    // note that the 10000-th prime is 104729
    // Be careful abt the range of the SPF while using the `modified_sieve` funtion. Increase the size if needed & within in possible limit.
    vector<int> primes = modified_sieve(104729);
    int n = 10000;
    cout << primes[n - 1] << "\n";
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    //cin >>  t; 
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
