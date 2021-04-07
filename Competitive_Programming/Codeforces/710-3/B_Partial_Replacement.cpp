#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int count = 1;
  int i = s.find('*');
  while (true) {
    
    int j;
    if (i + k > n-1){
      j = n-1;
    }
    else{
      j =  i+ k;
    }

    // We start looking from the end of the possible range in each case.
    for (; i < j && s[j] == '.'; j--) {}

    // j contains the index of last occurence of '*'. 
    // If the last & first are same itself, we are done.
    if (i == j) {
      break;
    }

    count++;

    // Updating the start point as the end point of last iteration.
    i = j;
  }

  cout << count << "\n";

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