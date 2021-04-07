#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;


void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    
    map<int,int> valid;
    int c0 = 1;
    int c1 = 1;
    for (int i = 0; i < a.size(); i++){

        if (a[i] == '0'){
            c0++;
        }
        else{
            c1++;
        }

        if (c0 == c1){
            valid[i] =  1;
        }

    }


    if (a[n-1] != b[n-1]){

        // Not Valid
        if (valid[n-1] == 0){
            cout << "NO" << endl;
            return ;
        }
    }


  for (int i = n-2; i >= 0 ; i--){

      if ( ( a[i] != b[i] ) and ( a[i+1] == b[i+1] )){

            // Not Valid
            if (valid[i] == 0){
            cout << "NO" << endl;
            return ;
            }
      } 

    if ( ( a[i] == b[i] ) and ( a[i+1] != b[i+1] )){

            // Not Valid
            if (valid[i] == 0){
            cout << "NO" << endl;
            return ;
            }
        
    }

  }

      cout << "YES" << endl;
            return ;

}

int main() {
    fastIO;
    int t = 1;
    cin >> t; // Comment if only 1 testcase.
    while(t--) {
      solve();
    }

    return 0;
}