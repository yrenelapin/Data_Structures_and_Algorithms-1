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
  cin >> n ;

  map<int, int> freq;
  for (int i = 0; i <n ; i++){
    int temp; cin >> temp;
    freq[temp]++;
  }

  priority_queue<int> q;
  for(auto itr = freq.begin(); itr != freq.end(); itr++){
    q.push(itr->second);
  }

  int res = n;
  while (q.size() >= 2){
      int fir = q.top(); q.pop();
      int sec = q.top(); q.pop();
      res -= 2;
      if (fir-1 >0 )  q.push(fir-1);
      if (sec-1 >0 )  q.push(sec-1);
  }

  cout << res << endl;

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