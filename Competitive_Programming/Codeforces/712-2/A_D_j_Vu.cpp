#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  
  int no_a = count(s.begin(), s.end(), 'a' );
  
  if (no_a == s.size()){
      cout << "NO" << endl;
      return;
  }
  else{

        int flag = 0;
        
        // At the beginning
        string temp = s;
        temp.insert(0 , "a");
        if ( !equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin() ) ){
            flag = 1;
            cout << "YES" << endl;
            cout << temp << endl;
        }

        if (flag == 1){
            return;
        }


        // At the end
        temp = s;
        temp.insert(s.size() , "a");
        if ( !equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin() ) ){
            flag = 1;
            cout << "YES" << endl;
            cout << temp << endl;
        }

        if (flag == 1){
            return;
        }

        // In the middle
        temp = s;
        temp.insert(s.size()/2 , "a");
        if ( !equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin() ) ){
            flag = 1;
            cout << "YES" << endl;
            cout << temp << endl;
        }

        if (flag == 0){
            cout << "NO" << endl;
            return;
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