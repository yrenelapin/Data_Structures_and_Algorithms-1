#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void sort_by_freq(int arr[], int n)
{
    int max, mode, temp_arr[n];
    
    max = *max_element(arr, arr + n);
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    
    vector<int> v ;     
    for (int j =0 ; j < n ; j++){
        if ( find(v.begin(), v.end(), arr[j]) == v.end() ){
            v.push_back(arr[j]);
        }
    }
   // cout << v.size() << " ";
    multimap<int,int, greater<int>> m;
    for (int j = 0 ; j < v.size() ; j++){
        // cout << "I am here" ;
        int search_for =  v[j];
        int freq_ = count[search_for];
        m.insert(make_pair(freq_, search_for));
        // cout << "I am here still" << "\n";    
    }
        
    
    // cout << "Size" << m.size() << " ";

    for(auto itr = m.begin(); itr != m.end() ; itr++){
        // cout << (itr->first) << " ";
        for (int i = 0 ; i < (itr->first) ; i++){
            cout << itr->second << " " ;      
        }   
    }
}

int main()
{
    int  N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort_by_freq(arr, N);
    return 0;
}
