#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define ll long long
const int mod = 1e9 + 7;

void solve() {

  ll n;
  cin >> n;

  ll count = 0;
  vector<ll> input(n);

  for (ll i = 0; i < n ; i++){
    cin >> input[i];
  }

  ll x =  *min_element(all(input));

  for ( ll i : input){

      if (i == x){
        count++;
      }

      // Checking if x is a SUPERMASK of all other elements.
      if ( (i&x) != x){
        cout << 0 << endl;
        return;
      }

  }

  if (count < 2){
        cout << 0 << endl;
        return;
  }

  // 1st position can take any one element from count.
  // Last position can take any element from remaining  `count-1` elements.
  // Remaining (n-2) can be arranged in any manner. 
  ll temp =  ( (count)*(count-1) ) % mod ;

  // computing (n-2) factorial
  ll factorial = 1;
  for (ll i = 1; i<=n-2; i++) 
    { factorial = (factorial*i) %mod; }

  ll final  = ( factorial*temp )% mod;
  cout << final << endl;
  return;

}


int main() {
    fastIO;
    ll t = 1;
    cin >> t; // Comment if only 1 testcase.
    while(t--) {
      solve();
    }

    return 0;
}