#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
 
  
int main() {
    
    fastIO;
    ll arr[] =  {1,2,3,4,5,6,7,8,9,10};        
    ll x = 8;
    
    ll low = 0;
    ll high = sizeof(arr)/sizeof(arr[0]) -1;
    ll mid ;
    while (high > low){
        
        mid = (high + low)/2;

        if ( arr[mid] > x )  {
            high = mid;
        }
        else if  ( arr[mid] < x ) {
            low = mid;
        }
        else{
            break;
        }
    }

    if (arr[mid] == x) {
        cout << "found";
    }
    
    // deb(arr[mid]); deb2(arr[low], arr[high]);
}   