#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m ;
        cin >> n >> m;
        int n_safe = n;
        int m_safe = m;
        vector<int> a,b,c;
        
        while(n--){
            int temp ; cin >> temp;
            a.push_back(temp);
        }
        
        while(n_safe--){
            int temp ; cin >> temp;
            b.push_back(temp);
        }
        
        while(m--){
            int temp ; cin >> temp;
            c.push_back(temp);
        }

        unordered_map<int, int> map_;
        for (int i= 0;  i< a.size();  i++){
            if (a[i] != b[i]){
                map_.insert(make_pair(b[i],i)); // Color req, Index
            }
        }

        
        vector<int> ind;
        
        
        if (map_.size() == 0){
            
        }
        
        if (map_.size() > m_safe){
            cout << "NO" << "\n";
            continue;
        }


        else{



            for (int k = 0; k < c.size(); k++){
                
                if ()

            }

        }

        

        
    }
}