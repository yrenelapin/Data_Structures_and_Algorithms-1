#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long int ll;
const long long INF=1e18;

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.
Example

Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.

*/
const int N = 1000000;
ll t, n, c;
ll stalls[N];


// Check if the cows can be placed with a minimum distance of `d` between them.
ll check (ll d){

    ll last =  -INF;
    ll cnt = 0;
    for (ll i = 0; i < n ; i++){
        if (stalls[i] - last >= d){
            cnt++;
            last = stalls[i];
        }
    }

    if (cnt >= c){
        return 1;
    }
    else{
        return 0;
    }

}


int main() {
    fastIO;
    cin >> t;
    while (t--) {

        cin >> n >> c;
        for (ll i = 0 ;  i< n ; i++){
            cin  >> stalls[i];
        }
        
        // This is very Important.
        sort(stalls, stalls+n);


        // Now we iterate over all the possible Distances & find out the Largest Minimum Distance using Binary Search.
        ll l = 1; 
        ll u = INF;
        ll ans ;
        while (l <= u ){
                ll mid = (l + u )/2;

                if (check(mid)){
                    ans = mid;
                    l = mid+1;
                }
                else{
                    u = mid-1;
                }
        }

        cout << ans;

    }

    return 0;
}

/*
Refer this for explanation : https://www.youtube.com/watch?v=HoMJSSSU_fY
*/