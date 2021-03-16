#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    lli t;
    cin >> t;

    while (t--) {
        
        lli n;
        cin >> n;

        multiset<lli> miners;
        multiset<lli> diamonds;
        for (int i = 0 ; i < (2*n) ; i++){
            lli x, y ;
            cin >> x >> y;
            if (x == 0){
                miners.insert(y*y);
            }
            if (y == 0){
                diamonds.insert(x*x);
            }
        }
        
        cout.precision(17);
        cout  << fixed ;
        long double ans  = 0 ;
        auto itr_min = miners.begin();
        auto itr_dia =  diamonds.begin();
        
        while (itr_min != miners.end()){

            lli sum =  (*itr_min + *itr_dia );
            ans += sqrt(sum);

            itr_min++;
            itr_dia++;
        
        }

        cout << ans << endl;       
} 

}