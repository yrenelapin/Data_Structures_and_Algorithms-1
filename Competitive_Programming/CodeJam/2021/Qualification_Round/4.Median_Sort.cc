using namespace std;
#include <bits/stdc++.h>
#define ll long long int


// Small Bug in I/O. Need to fix!


// We will use Ternary Search since Test case 3 requires at max 170 queries, with n = 50., So we need N*logb(N) ~ 170 "b is the base", here b = 3.


int query(int x1, int x2, int x3){
    cout << x1 << " " << x2 << " " << x3 << endl;
    int r; cin >> r;
    assert(r != -1);
    return r;
}


int n;
void solve(){
    vector<int> result;
    {
    int y = query(1,2,3);
    // Inserting elements on the basis of query.
    // This can be done with if statements too.
    result = { 1+y%3, y, 1+(y+1)%3 };
    }
    // We start filling the numbers from 4 to n using ternary search to place it in correct position.
    for (int i= 4; i <= n  ; i++){
        
        int l = 0; int r = result.size()-1;

        while (l < r) {

            int m1 = l + (r-l)/3 ;
            int m2 = r - (r-l)/3 ;
            int x = query(result[m1], i, result[m2]);
            if (x == i){

                // Edge case
                if (m2-m1 == 1){
                    result.insert(result.begin()+m2, i);
                    break;
                }

                // These may vary depending upon the implementation of ternary search.
                l = m1+1;
                r = m2;

            }
            else if (x == result[m1]){
                
                r = m1;
                if ( r <= l){
                    result.insert(result.begin()+l, i);
                    break;
                }

            }
            else{
                
                l = m2;
                if ( r <= l){
                    result.insert(result.begin()+r+l, i);
                    break;
                }

            }


        }


    }

    for (int i = 0; i <n ; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    int z;
    cin >> z;
    assert(z==1);
    // Raises an error if z is not equal to 1.
    


}


int main()
{
    // In Interactive problems, using fastIO along with "endl" is sufficient
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1, q;
    cin >> t >> n >> q;
    while(t--){
        solve();
    }
    return 0;

}