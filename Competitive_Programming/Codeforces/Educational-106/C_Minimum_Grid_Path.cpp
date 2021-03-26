#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef unsigned long long int ll;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n ;
        vector<ll> c;
 
        // c0,c1,...cn-1
        for (ll i = 0 ;  i< n ; i ++){
            ll temp;
            cin >> temp;
            c.push_back(temp);
        }
        
        ll cost = ULLONG_MAX;
 
        vector<ll> list_sums;
        vector<pair<ll,ll>> min_values;
        for (ll k = 1;  k < n; k++){
 
                ll curr_cost = 0;
 
                if (k==1){  
 
                        ll even_count = ceil((k+1)/2.0) ;
                        ll odd_count = k+1 - (even_count);
                        
                        ll even_min = ULLONG_MAX;  ll odd_min = ULLONG_MAX;
                        ll current_sum =  0;
                        
                        for (ll i = 0 ;  i <= k ; i++){
                            
                            current_sum += c[i];
                            if (i % 2 == 0){
                                even_min =  min(even_min, c[i]);
                            }
                            else{
                                odd_min =  min(odd_min, c[i]);
                            }
 
                        }
 
                        list_sums.push_back(current_sum);
                        min_values.push_back(make_pair(even_min, odd_min));
 
                        curr_cost = ( current_sum + even_min*(n - even_count) + odd_min*(n- odd_count) );
                        cost = min(cost, curr_cost);  }
                else{   
 
                    ll current_sum = list_sums[list_sums.size()-1] + c[k] ;
                    ll even_count = ceil((k+1)/2.0) ;
                    ll odd_count = k+1 - (even_count);
                    
                    ll even_min = min_values[min_values.size()-1].first;
                    ll odd_min = min_values[min_values.size()-1].second;
                    
 
                    if (k % 2 ==0){
                        even_min =  min(even_min, c[k]);
                    }
                    else{
                        odd_min = min(odd_min, c[k]);
                    }
 
 
                    list_sums.push_back(current_sum);
                    min_values.push_back(make_pair(even_min, odd_min));
 
                    curr_cost = ( current_sum + even_min*(n - even_count) + odd_min*(n- odd_count) );
                    cost = min(cost, curr_cost);  }
                }
 
              
        
        cout << cost << endl;
 
    }
 
    return 0;
}