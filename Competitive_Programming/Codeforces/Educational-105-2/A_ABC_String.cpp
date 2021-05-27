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

// From GFG
bool isBalanced(string exp)
{
    // Initialising Variables
    bool flag = true;
    int count = 0;
  
    // Traversing the Expression
    for (int i = 0; i < exp.size(); i++) {
  
        if (exp[i] == '(') {
            count++;
        }
        else {
            // It is a closing parenthesis
            count--;
        }
        if (count < 0) {
            // This means there are
            // more Closing parenthesis
            // than opening ones
            flag = false;
            break;
        }
    }
  
    // If count is not zero,
    // It means there are more
    // opening parenthesis
    if (count != 0) {
        flag = false;
    }
  
    return flag;
}


void solve() {
    string s; cin >> s;
    
    set<char> poss = {'A', 'B','C'};

    ll n = s.size();
    if (s[0] == s[n-1]){
        cout << "NO";
    }
    else{
        char fir =  s[0];
        char last = s[n-1];

        poss.erase(fir);
        poss.erase(last);

        ll c_fir = 0;
        ll c_last = 0;
        fr(i,0, n-1){
            if (s[i] == fir){
                s[i] = '(';
                c_fir++;
            }
            if (s[i] ==  last){
                s[i] = ')';
                c_last++;
            }
        }

        ll rem = abs(c_fir- c_last);
        if (n != rem +  c_fir + c_last  ){
            cout << "NO";
        }
        else{

             if (c_fir > c_last){
                 fr(i,0, n-1){
                    if (s[i] == *poss.begin()){
                        s[i] = ')';
                    }
                 }
             }

             if (c_fir < c_last){
                 fr(i,0, n-1){
                    if (s[i] == *poss.begin()){
                        s[i] = '(';
                    }
                 }
             }
             
            if (isBalanced(s) ){
                cout << "YES";
            }
            else{
                cout << "NO";
            }




        }



    }

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