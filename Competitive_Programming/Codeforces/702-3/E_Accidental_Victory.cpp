    #include <bits/stdc++.h>
    using namespace std;
    #define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    #define all(x) (x).begin(), (x).end()
    #define deb(x) cout << #x << " = " << x << endl
    #define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
    typedef long long ll;
    
    
    bool Can_Win(ll position, vector<ll> &sorted_input){
        
        ll curr_tokens = sorted_input[position];
        for (ll i = 0 ;  i<sorted_input.size() ; i++){
            
            if (i == position){
                continue;
            }
    
            if ( curr_tokens < sorted_input[i]){
                return false;
            }
    
            curr_tokens += sorted_input[i];
        }
    
        return true;
    
    }
    
    int main() {
        
        fastIO;
        ll t, n, temp;
        cin >> t;
        while (t--) {

            vector<ll> input;
            vector<ll> sorted_input;
            
            cin >> n;
            for (ll  i = 0; i <n; i++){
                cin >> temp;
                input.push_back(temp);
                sorted_input.push_back(temp);
            }
    
            sort(all(sorted_input));
    
            ll low = 0;
            ll high = n-1;
            ll mid;
            while (high > low){
                
                mid = (high + low)/2;
    
                if (Can_Win(mid, sorted_input)){
                    high = mid;
                }
                else{
                    low = mid+1;
                }
            }
            
            vector<ll> result;
            for (ll i = 0; i <n ; i++){
                if (input[i] >= sorted_input[high]){
                    result.push_back(i+1);
                }
            }
    
            cout << result.size() << endl;
            for (ll i = 0; i< result.size() ; i++){
                cout << result[i] << " ";
            }
    
            cout << endl;
    
        }
    
        return 0;
    }