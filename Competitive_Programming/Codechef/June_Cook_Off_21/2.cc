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
//-------------------------------------------------------- Basic Number Theory --------------------------------------------------
namespace number_theory{
    int gcd(int a, int b)   { int c;  while (b){c = b; b = a % b; a = c;} return a; }
    int lcm(int a, int b)   { return (a*(b/gcd(a,b)));}
    int modpow(int a, int p = M-2, int MOD = M )   { int result = 1; while (p > 0) { if (p & 1) { result = a * result % MOD; } a = a * a % MOD; p >>= 1; } return result; }
    int ncr (int n,int k)    { int ans = 1; if (k>n-k) {k=n-k;} fr(i,1,k) {ans*=(n-i+1); ans/=i; } return ans; }
}
using namespace number_theory;
// ----------------------------------------------------------------------------------------------------------------------//


void solve() {
  int n; cin >> n;
  map<int,int> m;
  vi v(n); fr(i,0,n-1) { cin >> v[i]; m[v[i]]++; }

  if ( n < 3){

      if (n == 1){ 
          cout << 0 << endl;
      }
      else if (n==2){
          if ( (v[0]^v[1]) > 0 ){
              cout << 0 << endl;
          }
          else{
              cout << -1 << endl;
          }
      }

  }
  else{
      // n >= 3, we can perform op & check


        int found = -1;
        trav(e, m){
            if (e.se >= 2){
                found = e.fi;
                break;
            }
        }

        if (found == -1){  // No elem is repeated atleast twice.
            cout << -1 << endl;
            return;
        }
        else{

            int one = find(all(v), found) - v.begin();
            int two;
            
            frr(i, n-1, 0){
                if (v[i] == found ){
                  two = i;
                  break;
                }
            }

        
            if (n == 3){
                
                int rem = -1;
                fr(i,0,2){
                    if (i != one and i != two){
                        rem = i;
                    }
                }

                if (abs(one-two) == 1    or v[rem] == v[one]){
                    cout << -1 << endl;
                    return;
                }
                else{
                    //done.
                    cout << 0 << endl;
                    return;
                }
            }
            else{  // n >= 4

                
            vvi results;

            // Making all the other elements 0.
            fr(i,0,n-1){
                if (i != one and i != two){
                    v[i] = 0;
                    results.pb({one+1,two+1,i+1});
                    //cout << one << " " << two << " " << i << endl;
                }
            }
            
            // 1st element is 0.  // 0, found, 0, found,...  (at odd pos-> found)
            if (v[0] == 0){

                fr(i,1,n-1){
                    if (i != one and i != two){
                        if (i % 2 == 1){   
                            results.pb({1, one+1 ,i+1});
                            // v[i] = 0 XOR one.
                        }
                        else{
                            results.pb({one+1, two+1, i+1});
                        }   
                    }
                }
                

                if ( one%2 == 1 and two%2 == 1){
                    // Done.
                }
                else if (one%2 == 0 and two%2 == 1){

                    if (two != 1){
                        // n >= 4
                        // change the v[one] from found to 0.
                        results.pb(  { 2,  two+1  ,one+1}  );
                    }
                    else{
                        results.pb(  { 4,  two+1  ,one+1}  );
                    }     
                
                    
                }
                else if (one%2 == 1 and two%2 == 0){

                    if (one != 1){
                        // n >= 4
                        // change the v[one] from found to 0.
                        results.pb(  { 2,  one+1  ,two+1}  );
                    }
                    else{
                        results.pb(  { 4,  one+1  ,two+1}  );
                    }   

                }
                else{
                    // Both needs to converted to 0.
                    
                    // n >= 4
            
                    results.pb(  { 2,  one+1  ,two+1}  );

                    results.pb(  { 2, 4, one+1}  );
                }
                
            }
            // found, 0, found, 0 , ...  (at odd pos-> 0)
            else if (v[0] == found){

                fr(i,1,n-1){
                    if (i != one and i != two){

                        if (i % 2 == 1){   // At odd positions. 
                            results.pb({1, one+1 ,i+1});
                            // v[i] = found XOR found = 0
                        }
                        else{
                            // v[i] = 0 XOR found = found.
                            results.pb({2, two+1, i+1});
                        }   
                    }
                }
                

                if ( one%2 == 0 and two%2 == 0){
                    // Done.
                }
                else if (one%2 == 0 and two%2 == 1){

                    // n >= 4
                    // change the v[two] from found to 0.

                    if (one != 0){
                                results.pb(  { 1,  one+1  ,two+1}  ); }
                    else{
                               results.pb(  { 3,  one+1  ,two+1}  ); 
                    }
                }
                else if (one%2 == 1 and two%2 == 0){

                    // n >= 4
                    // change the v[one] from found to 0.

                    if (two != 0 ){
                    results.pb(  { 1,  two+1  ,one+1}  ); }
                    else{
                         results.pb(  { 3,  two+1  ,one+1}  ); 
                    }
                }
                else{
                    // Both needs to converted to 0.
                    
                    // n >= 4
                    results.pb(  { 1,  one+1  ,two+1}  );

                    results.pb(  { 1, 3, one+1}  );
                }
                
            }


                cout << results.size() << endl;
                trav(e,results){
                    trav(o,e){
                        cout << o << " ";
                    }
                    cout << endl;
                }
               
                

            }
            



        }


  }


}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;
    cin >>  t; 
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        //cout << "\n";
    }
    return 0;
}
