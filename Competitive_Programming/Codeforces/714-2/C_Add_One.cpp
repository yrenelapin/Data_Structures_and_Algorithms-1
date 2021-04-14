#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define ll long long

const int mod = 1e9 + 7;
const int max_m = 2*(1e5) ;

// size that is to be found.
ll size_;

// dp[i] contains the size of the 10 after applying i operations to it.
ll dp[max_m];

void compute(){

    for (int i = 0; i < max_m; i++){

        if ( i <= 8 ){
            dp[i] = 2;
        }
        else if (i == 9){
            dp[i] = 3;
        }
        else{
            dp[i] = ( dp[i-9] + dp[i-10] ) % mod;   // Taking mod at this step is very important.
        }

    }

}


void solve() {

  size_ = 0;
  int n,m;
  cin >> n >> m;
  size_ += ( log10(n)+ 1 );
  const int orig_size_ =  size_;


  string num = to_string(n);

  for (int i = 0; i < orig_size_; i++){

      int curr_m = m;
      int d_int = num[i] - '0';
    
      curr_m -= (10-d_int);
    
      if (curr_m >= 0){
          size_++;
          size_ += (dp[curr_m] - 2);
      }
  }

  cout << (size_ % mod ) << endl;
  return;

}

int main() {
    fastIO;
    int t = 1;
    cin >> t; // Comment if only 1 testcase.
    compute();
    while(t--) {
     
      solve();
    }

    return 0;
}