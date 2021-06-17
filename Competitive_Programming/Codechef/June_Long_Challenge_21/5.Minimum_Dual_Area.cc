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

ll n; 

ll compute_area(ll i, ll a, ll b, vpl &v){
    ll part1 = (v[i].fi -v[0].fi)*(a);
    ll part2 = (v[n-1].fi-v[i+1].fi)*(b);
    return ( part1 + part2);
}

void solve()
{   
    cin >> n;
    vpl input_coor(n); 
    multiset<ll> x_coor,y_coor;
    fr(i,0,n-1) {
        cin >> input_coor[i].fi >> input_coor[i].se;
        x_coor.insert(input_coor[i].fi);  
        y_coor.insert(input_coor[i].se);
    }  

    // Sorting based on x values first, followed by y values.
    sort(all(input_coor)); 

    // trav(each, input_coor){
    //     deb2(each.fi, each.se);
    // }
    
    ll ans_y = INF;
    ll max_y = -INF, min_y = INF;

     // Traversing the first n-1 points which are sorted based on the `x` coordinates. 
     fr(i,0,n-2){
        
        // Tracking the difference between max & min `y` coordinates
        max_y = max(max_y,input_coor[i].second);
        min_y = min(min_y,input_coor[i].second);
        ll diff_y = max_y-min_y;

        // Erasing the current `y` coordinate from multiset
        y_coor.erase( y_coor.find(input_coor[i].second) );
        auto last = y_coor.end(); last--;
        auto first = y_coor.begin();
        ll diff_y_2 = ( *last - *first );

        //deb(diff_y_2);
        ll curr_area = compute_area(i, diff_y, diff_y_2, input_coor);

        ans_y = min(ans_y,curr_area);
    }

    //deb(ans_y);

    // Reversing the (x,y) coordinates to (y,x) pairs in the input provided,
    // so that we can sort by first priority to `y` values.
    vpl rev_coor(n); ll i = 0;
    tra(each, rev_coor){
        each.fi = input_coor[i].se;
        each.se = input_coor[i].fi;
        i++;
    }

    // Sorting based on y values first, followed by x values.
    sort(all(rev_coor));

    // trav(each_rev, rev_coor){
    //     deb2(each_rev.fi, each_rev.se);
    // }

    ll ans_x = INF;
    ll max_x = -INF, min_x = INF;

    // Traversing the first n-1 points which are sorted based on the `y` coordinates. 
     fr(i,0,n-2){
        
        // Tracking the difference between max & min `x` coordinates
        max_x = max(max_x,rev_coor[i].second);
        min_x = min(min_x,rev_coor[i].second);
        ll diff_x = max_x-min_x;

        // Erasing the current `x` coordinate from multiset
        x_coor.erase( x_coor.find(rev_coor[i].second) );
        auto last = x_coor.end(); last--;
        auto first = x_coor.begin();
        ll diff_x_2 = ( *last - *first );

        //deb2(diff_x, diff_x_2);

        ll curr_area = compute_area(i, diff_x, diff_x_2, rev_coor);
        ans_x = min(ans_x,curr_area);
    }

    // deb2(ans_x, ans_y);
    ll final_ans = min(ans_x, ans_y);

    if (final_ans == INF){
        cout << 0;
    }
    else{
        cout << final_ans;
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
