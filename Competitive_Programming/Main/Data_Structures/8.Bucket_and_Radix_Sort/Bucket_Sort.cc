#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ulld;

void Bucket_Sort(vector<ulld> &v){
    int n = v.size();
    
    vector<vector<ulld>> bucket_array;

    for(int k = 0; k<n; k++){
        vector<ulld> temp_;
        bucket_array.push_back(temp_);
    }

    for (int i = 0; i<n ; i++){
        int index = n*(v[i]);
        bucket_array[index].push_back(v[i]);
    }

    for(int j = 0; j<n; j++){
        sort(bucket_array[j].begin(),bucket_array[j].end());
    }

    for(int j = 0; j<n; j++){
        for (int k = 0; k < bucket_array[j].size(); k++){
           cout << bucket_array[j][k] << " ";
    }

    
}
    
}

int main(){
    int n;
    cin >> n;
    vector<ulld> v;
    while(n--){
        ulld temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << fixed;
    cout << setprecision(2);
    Bucket_Sort(v);
    return 0;
}