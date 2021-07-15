#include <bits/stdc++.h>
using namespace std;
int maxc = 26;
vector< vector<int> > adj_list(maxc+1); 

void topological_sort() {
    vector<int> in_degree(maxc+1, 0);
    vector<int> result;
    vector<bool> visited(maxc+1);
    priority_queue< int, vector<int>, greater<int> > queue;
    int cycle_check=0;

    // store indegree of every vertex
    for (int i = 0 ; i <= 25 ; i++) {
        for (auto u : adj_list[i]) {
            in_degree[u]++;
        }
    }

    // push vertices with indegree 0 to queue
     for (int i = 0 ; i <= 25; i++)  {
        if (in_degree[i]==0) {
            queue.push(i);
            visited[i] = true;
        }
    }

    while (!queue.empty()) {
        int vertex = queue.top(); queue.pop();
        result.push_back(vertex);   
        
        for (auto i : adj_list[vertex]) {
            if (!visited[i]){
                if (--in_degree[i] == 0) {
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
        cycle_check++;
    }
    
    
    // We know, If any element is not processed, It means we have a Cycle.
    if (cycle_check != maxc ) {
        cout << "No Order";
        return;
    }

    for (auto i : result)
        cout << (char)( 'a' + i);
        
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    
     for (int i = 0; i < n-1; i++){
         string one = input[i];
         string two = input[i+1]; int ind = 0;

         int flag = 0;
         while(ind < one.size() and ind < two.size()){
             if ( one[ind] != two[ind] ){
                 flag = 1;
                 adj_list[one[ind]-'a'].push_back(two[ind]-'a');
                 break;
             }
             ind++;
         }

        // If no element differs & previous one is of more length, Then such ordering is not possible according to definition.
         if (!flag and one.size()  > two.size()){
                cout << "No Order";
                return 0;
         }

         
     }
    topological_sort();
    return 0;
}