#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
// typedef long long int;

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        
        int n, w;
        cin >> n >> w;

        multiset<int> s;
        for (int j = 0; j < n; j++){
            int temp; cin >> temp;
            s.insert(temp);
        }

        int space_left = w;
        int height = 1;

        while(!s.empty()){
            auto itr =  s.upper_bound(space_left);
            if (itr != s.begin()){
                itr--;
                int value = *itr;
                space_left -= value;
                s.erase(itr);

            }
            else{

                height++;
                space_left = w;
            }
        }

        cout << height << endl;
    }

    return 0;
}