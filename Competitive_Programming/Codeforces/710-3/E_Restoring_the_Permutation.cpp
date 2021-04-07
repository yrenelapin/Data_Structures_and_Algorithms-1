#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void fill_remaining(vector<int> &v, bool minimize){

    set<int> remaining;
    for (int i = 1; i<= v.size(); i++){
        remaining.insert(i);
    }

    for(int i = 0; i <v.size();  i++){
        if (v[i] != -1){
            remaining.erase(v[i]);
        }
    }

    int lastplaced = -1;
    for (int i = 0; i <v.size(); i++){

        if (v[i] ==  -1){

            if (minimize){
                v[i] = *remaining.begin();
                remaining.erase(remaining.begin());
            }
            else{
                auto itr = remaining.lower_bound(lastplaced);
                itr--;
                v[i] = *itr;
                remaining.erase(itr);
            }
        }
        else{
            lastplaced = v[i];
        }


    }

}

void solve() {

    int n, temp;
    cin >> n ;
    vector<int> input, maxy(n,-1), miny(n, -1);

    for (int i = 0; i < n; i++){
        cin >> temp;
        input.push_back(temp);
    }

     int last_placed = -1;
     for (int i = 0; i < n; i++){

         if (last_placed != input[i]){
             maxy[i] = input[i];
             miny[i] = input[i];
         }
         
         last_placed = input[i];
     }

    fill_remaining(miny, true);
    fill_remaining(maxy, false);


    for (int i = 0; i < n; i++){
        cout << miny[i] << " ";
    }

    cout << endl; 

    for (int i = 0; i < n; i++){
        cout << maxy[i] << " ";
    }

    cout << endl; 
}

int main() {
    fastIO;
    int t = 1;
    cin >> t; // Comment if only 1 testcase.
    while(t--) {
      solve();
    }

    return 0;
}