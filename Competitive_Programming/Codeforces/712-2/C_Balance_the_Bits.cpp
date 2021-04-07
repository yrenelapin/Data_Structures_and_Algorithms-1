#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n; string s;
  cin >> n >> s;

  if (s[0] != '1' or s[n-1] != '1'){
      cout << "NO" << endl;
      return;
  }
  else{

      int count_A = count(all(s), '1');
      if ( (count_A % 2) != 0 ) {
            cout << "NO" << endl;
            return;
      }
      else{
            cout << "YES" << endl;
            vector<char> a(n), b(n);
            
            int co_a = 0;
            int temp_co = 0;
            for (int i = 0; i < n ; i ++){

                if (s[i] == '1'){
                    co_a++;
                    if (co_a <= count_A/2){
                        a[i] = '(';
                        b[i] = '(';
                    }
                    else{
                        a[i] = ')';
                        b[i] = ')';
                    }
                }
                else{
                    temp_co++;
                    
                    if ( temp_co % 2 == 0) {
                        a[i] = '(';
                        b[i] = ')'; 
                    }
                    else{
                        a[i] = ')';
                        b[i] = '('; 

                    }
                }

            }

            for (int j = 0;  j< n ; j++){
                cout << a[j] ;
            }
            cout << endl;

            for (int j = 0;  j< n ; j++){
                cout << b[j] ;
            }
            cout << endl;

      }

  }
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