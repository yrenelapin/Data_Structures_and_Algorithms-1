#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;

int main() {
    fastIO;
    ifstream MyReadFile("input.txt");
    string myText;
    string temp;


    getline (MyReadFile, temp);
    int t = stoi(temp);

    getline (MyReadFile, temp);
    int p = stoi(temp);
    
    for ( int T = 1; T <= t ; T++){        
        ll mean_correct  = 0;
        unordered_map<int,int> results;
        int count = 1;
        while (getline (MyReadFile, myText)) {

            int c = 0;
            for ( int i = 0; i < myText.size() ;  i++){
                if (myText[i] == '1'){
                    c++;
                }
            }
           
            results[c] = count;
             mean_correct += c;
            count++;
        }

        // cout << "Case #" << T << ": " << results.begin()->second << endl;


            ll mean_final = (mean_correct/100);
            deb(mean_final);
            for (auto itr =  results.begin(); itr!= results.end();  itr++){
            if ( ( itr->first > (1.5)*mean_final) ){
                    cout << "Case #" << T << ": " << itr->second << endl;
                    // break;
            } 
            }
    }
    return 0;
}