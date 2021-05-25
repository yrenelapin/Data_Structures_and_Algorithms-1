#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef unsigned long long ll;
const ll mod = 1e9 + 7;

void solve() {

  ll n; cin >> n;
  vector<ll> x(n);
  for (ll i = 0; i <n ; i++){
      cin >> x[i];
  }

   ll count = 0; 

   for (ll i = 0; i <n-1 ; i++){

       // Not in req order
       if ( x[i] >= x[i+1]){

           ll di_last = log10(x[i]) + 1;
           ll di_curr = log10(x[i+1]) + 1;
           ll needed = di_last - di_curr;  

           while ( x[i] >= x[i+1]){
               
               ll last =  x[i] % 10 ; last++;
               if ( last == 10){
                   x[i+1] = x[i+1]*pow(10, needed) ;
                   if (needed == 0 ){
                       count++;
                   }
                   else { count += (needed); }
               }
               else{ 
                  
                  x[i+1] = x[i+1]*pow(10, needed) + last;

                    if (needed == 0 ){
                       count++;
                   }
                   else { count += (needed); }
                    }

                needed = 1;
           }
       }

   }

   // cout <<  x[0] << " " << x[1] << " " << x[2] << " "; 
   cout << count << endl;

   


}

int main() {
    fastIO;
    ll t = 1;
    cin >> t; // Comment if only 1 testcase.
    
    for(ll a = 1; a <= t; a++ ){

    cout << "Case #" << a << ": ";
      
    solve();


    }

    return 0;
}