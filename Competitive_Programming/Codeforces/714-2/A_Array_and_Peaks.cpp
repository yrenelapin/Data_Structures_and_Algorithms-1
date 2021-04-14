#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
    int n,k;
    cin >> n >> k;


    if ( k > (n-1)/2 ){
        cout << -1 << endl;
        return;
    }

   vector<int> v(n);
   for (int i = 1; i<= n; i++){
       v[i-1] = i;
   }  

    int flag = 0;

    if (k==0){
         for (int i = 0; i< n; i++){
                      cout << v[i] << " ";
                  }

                  cout << endl;
                  return;
    }

    // works for n>=3
    // 1,....n-2
    for (int i = 1; i< n-1; i+=2){
        swap(v[i], v[i+1]);
        flag++;
        if (flag == k){
                  for (int i = 0; i< n; i++){
                      cout << v[i] << " ";
                  }

                  cout << endl;
                  return;
        }
    }

    if ( n==1 ){ 
        
        if(k==0){
          cout << v[0] << endl; }
          
           else{
                cout << -1 << endl;
                return;
        }
    }
    
    if (n==2){

        if (k==0){
          cout << v[0] << " " << v[1] << endl; }
        else{
                cout << -1 << endl;
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