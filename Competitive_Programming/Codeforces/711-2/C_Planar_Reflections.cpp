#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef unsigned long long ll;
const int mod = 1e9 + 7;

const int N = 1001;
const int K = 1001;

ll n,k; 
ll v[N][K][2];


// Curr is the number of the plane to which the particle is currently striking. 
ll solve(ll curr , ll k , ll dir){

    // Base Case
    if (k==1){
        return 1;
    }

    // This is the Recursive Memoisation step. 
    // If we have already visited the state, We just return its value instead of recomputing.
    if (v[curr][k][dir] != -1){
        return v[curr][k][dir];
    }

    // The particle hitting the plane `curr` and its copy which is being reflected  
    ll count = 2;


    // Let 1 be from left to right.
    if (dir == 1){

        // If we are not in the last plane
        if ( curr < n){
            count += solve(curr+1, k, dir)-1;   // -1 is to avoid recounting the particle since it is already counted in `count`
        }

        count %= mod;

        if (curr > 1){
            count += solve(curr-1, k-1, 1-dir)-1;
        }

        count %= mod;

        v[curr][k][dir] =  count;

    }

    // If particle hits from right to left.
    else{

        // If we are not in the last plane
        if ( curr < n){
            count += solve(curr+1, k-1, 1-dir)-1;
        }

        count %= mod;

        if (curr > 1){
            count += solve(curr-1, k, dir)-1;
        }

        count %= mod;
        v[curr][k][dir] =  count;
    }

    return count;

}


int main() {
    fastIO;
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(v, -1, sizeof(v));
        cout << solve(1, k, 1) << endl;
    }
    return 0;
}