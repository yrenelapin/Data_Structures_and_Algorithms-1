#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " , " << #y << "=" << y << endl

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--) {
        
        ll n, m, available_friends;
        cin >> n >> m ;

        // vector consisting of available students Each day 
        vector<ll> sch[m+1];

        vector< pair<ll, ll> >v;
        ll result[m+1] = {0};

        for (ll i = 0 ; i < m ; i++){

            cin >> available_friends ;

            for (ll j = 0 ; j < available_friends ; j++){

                ll temp2; cin >> temp2;

                sch[i+1].push_back(temp2);

            }

            // No of friends available on each day. 
            v.push_back({available_friends, i+1});
        }


        sort(v.begin(), v.end());

        map<ll,ll> helper_map;  
        
        // The Key point in this problem is the GREEDY CHOICE of Choosing the day with the minimum number of candidates
        // available and start filling. 

        // Iterating over the days but in the sorted order of the number of friends available.
        for (ll i = 0; i< v.size(); i++){
        
            // `v[i].second` has the day number. sch[`daynumber`] gives the list of available friends on that day.
            for (ll j = 0 ; j < sch[v[i].second].size(); j++ ){
    
                // Checking the freq of the friend. Note that, ceil(m/2) would not yield corect value of ceil of m/2 since c++ round the value of m/2 inside first.
                 if( helper_map[ sch[v[i].second][j] ] < ( (m+1)/2 )  ) {

                    // Inserting a friend at `v[i].second` day.
                    result[v[i].second] = sch[v[i].second][j];

                    // Increasing the frequency of that friend.
                    helper_map[sch[v[i].second][j]]++;

                    // Once we found a friend for a day, we can break out and move to other day. 
                    break;
                }

            }

        }


        // Checking if any day is left.
        ll flag = 1;
        for(ll i = 1; i<=m; i++){
            if (result[i]==0){
            flag=0;
            break;
            }
        }

        // If still any day is not filled with friend.
        if ( flag == 0 )  { cout <<"NO"; }
        else { 
            cout <<"YES"<<endl;
            for( ll i=1; i<=m; i++){
                cout << result[i] <<" "; }
        }
        cout<<endl;
       
    }

}