#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<int> v;
        while(n--){
            int temp ; cin >> temp;
            v.push_back(temp);
        }

        int pos ;
        int flag = 0;
        for (int i = 1; i<k+1; i++){
            int inner = 0;
            for (int j = 0; j<(v.size()-1); j++){
                if (v[j] < v[j+1]){
                    v[j]++;
                    pos = j+1;
                    inner = 1;
                    break;
                }   
            }
            
            if (inner == 0){
                flag = 1;
                cout << -1 << "\n";
                break;
            }
            
        }


        if (flag == 0){
            cout << pos << "\n";
        }


        
    }
}