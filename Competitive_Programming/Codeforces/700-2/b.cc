#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <string>

typedef long long int ll;
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll A, B, n;
        cin >> A >> B>> n;
        vector<ll> a,b;
        map<ll,ll> attac_health;
        
        for (ll  i = 0 ; i< n ; i++){
            ll temp ;cin >> temp ; 
            a.push_back(temp);
        }
        
        for (ll  i = 0 ; i< n ; i++){
            ll temp ;cin >> temp ; 
            b.push_back(temp);
        }

        for (ll  i = 0 ; i< n ; i++){
            attac_health.insert(make_pair(a[i], b[i]));
        }

        ll dead_count = 0;


        for ( auto itr = attac_health.begin(); ( B >= 1 && itr != attac_health.end()) ; itr++){
            ll health_i = itr->second;

            while( health_i >= 1 ){
                health_i -= A;
                B -= itr->first;

                if (B < 1){
                    break;
                }
            }

            if (health_i < 1 ) dead_count++;
        }
       

        // cout << dead_count << "\n";
        if ( dead_count == n ){
            cout  << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }

      

    }
}