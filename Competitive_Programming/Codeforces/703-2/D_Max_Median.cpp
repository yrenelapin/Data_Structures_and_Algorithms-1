#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef unsigned long long int ull;


int main(){
    fastIO
    int n,k;

    cin >> n >> k;
    
    vector<int> v ;
    int temp; 
    for (int  i = 0; i<n ; i++){
        cin >> temp;
        v.push_back(temp);
    }


    int m = 0;

    for (int i = 0;  i< n-k ; i++){

        vector<int> t =  v;
        for (int le = k ; le <= n ; le++ ){

            sort( t.begin()+i, t.begin()+i+le ) ;

            int res = t[(i+le/2)];
    
            m = max(res, m);

        } 
        t.clear();

    }

    cout << m ;
}