#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    lli t;
    cin >> t;

    while (t--) {
        
        lli n,k;
        cin >> n >> k;

        lli temp;
        map<lli,lli, greater<int>> m;
        for (lli i = 0; i <n; i++){
            cin >> temp;
            m[temp] = 1;
        }

        
        lli a = m.begin()->first;
        lli b;
        for (lli i = 0; ; i++){
            if (m.count(i) == 0){
                b = i;
                break;
            }
        }
        
        
        if (k == 0) {cout << n ;}

        else if ( b == a+1){
                cout << (n+k);}

        else{
            lli toadd = ceil((a+b)/2.0);
            m[toadd] = 1;
            cout << m.size();
        }

        cout << endl;

        }
} 