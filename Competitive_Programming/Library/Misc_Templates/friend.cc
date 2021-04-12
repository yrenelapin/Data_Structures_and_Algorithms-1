#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef priority_queue<ll> prq;
#define vt vector
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(e,a) for(auto (e): (a))
#define tra(e,a) for(auto& (e): (a))
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define sz(x) (ll)(x).size()
#define IOS ios::sync_with_stdio(0);cin.tie(0) 
#define decimal(x) cout << fixed << setprecision(x)
#define dbg1(x9) cout << #x9 << " = " << x9 << endl
#define dbg2(x9, y9) cout << #x9 << " = " << x9 << "   " << #y9 << " = " << y9 << endl
#define dbg3(x9, y9, z9) cout << #x9 << " = " << x9 << "   " << #y9 << " = " << y9 << "  "<< #z9 <<" = "<< z9 << endl
#define dbg4(x9, y9, z9, w9) cout << #x9 << " = " << x9 << "   " << #y9 << " = " << y9 << "  "<< #z9 <<" = "<< z9 << "  " << #w9 <<" = "<< w9 << endl
#define get5(a9, b9, c9, d9, e9, ...) e9
#define DBG(...) get5(__VA_ARGS__, dbg4, dbg3, dbg2, dbg1)
#define dbg(...) DBG(__VA_ARGS__)(__VA_ARGS__)
 
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> istream &operator>> (istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream& operator<< (ostream& os, const vector<T>& v) 
{ os << "[ "; for (int i = 0; i < v.size(); ++i) { os << v[i]; if (i != v.size() - 1) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const set<T>& v) 
{ os << "[ "; for (auto it : v) { os << it; if (it != *v.rbegin()) os << ", "; } os << " ]\n"; return os; } 
template <typename T> ostream& operator<< (ostream& os, const multiset<T>& v) 
{ os << "[ "; for (auto it : v) os << it << ", "; os << " ]\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const map<T, S>& v) 
{ os << "{ "; for (auto it : v) os << it.first << " : " << it.second << ", "; os << " }\n"; return os; }
template <typename T, typename S> ostream& operator<< (ostream& os, const pair<T, S>& v) 
{ os << "("; os << v.first << ", " << v.second << ")"; return os; }
template <typename T> ostream& operator<< (ostream& os, min_heap<T> p)
{ os << "[ "; while(!p.empty()){ os << p.top() << " ,"; p.pop(); } os << " ]\n"; return os; }
 
inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const long long INF=1e18;
const ll mod=1e9+7;
 
void solve(){
    ll n; cin >> n; string s; cin >> s; ll N=n-1; vt<bool> used(n,0); min_heap<pl> mh; ll cur=0,pos,ans=0;
    fr(i,0,n-1){ if(!cur) pos=i; ++cur; if(i+1>=n || s[i+1]!=s[i]){ if(cur>1) mh.push({pos,cur}); cur=0; } } ll i=0; //dbg(mh);
    while(i<n){ //dbg(i-1,used);
        bool f=0;
        if(used[i]){ ++i; continue; }
        while(sz(mh) && mh.top().fi<i) mh.pop();
        if(sz(mh)){
            pl pr=mh.top(); mh.pop(); used[pr.fi]=1; if(pr.se-1>1) mh.push({pr.fi+1,pr.se-1}); f=1; //dbg(pr);
        } else{ while(N>=0 && used[N]) --N; if(N>=0){ used[N]=1; f=1; } }
        while(i<n && used[i]) ++i; if(i<n){ f=1; char c=s[i]; while(i<n && (used[i] || s[i]==c)){ used[i]=1; ++i; } }
        if(f) ++ans;
    } cout << ans;
}
 
int main(){
    IOS;
    int t = 1;
    cin >>  t;
    
    for(int t1=1;t1<=t;++t1){
        //cout << "Case #" << t1 << ": ";
        solve();
        cout << '\n';
    }
}