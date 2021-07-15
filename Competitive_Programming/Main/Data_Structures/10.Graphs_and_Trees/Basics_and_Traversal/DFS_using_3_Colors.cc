#include <bits/stdc++.h>
using namespace std;

int n = 1e5 + 1;

vector< vector<int> > adj_list(n+1);
    
/*
0 -> White ( Unprocessed )
1 -> Gray ( Processing )
2 -> Black (Processed )
*/

vector<int> traversalColor(n+1, 0);

// Recursive - O(|V| + |E|)
void DFS(int vertex){

    traversalColor[vertex] = 1;
    cout << vertex << " ";   // Process the node here.
 
    for (auto i : adj_list[vertex]){
        if ( traversalColor[i] == 0){   
            DFS(i);
        }
    }
    
    // Now the `vertex` node is processed.
     traversalColor[vertex] = 2;
}

// Iterative - O(|V| + |E|)
void DFS_Iter(int vertex){

    stack<int> s;
    traversalColor[vertex] = 1;
    s.push(vertex);

    while(!s.empty()){

        int curr = s.top(); s.pop();

        // Process the Node
        cout << curr << " ";

        for (auto i : adj_list[curr]){
            if (traversalColor[i] == 0){
                s.push(i);
                traversalColor[i] = 1;
            }
        }
        
        // Now the `curr` node is processed.
        traversalColor[curr] = 2;

    }
}

int main()
{
    // Graph as an Adjacency List with n vertices assuming that all vertex numbers are <= n and having `m` edges.
    // For weighted graph, use vector< vector< pair<int,int> > > adj_list(n+1);  and push { destination, weight }
      
    cin >> n;
    int vertex, destination;
    for (int i = 0; i < n; i++){
            cin >> vertex; int dest;
            while (1){
                cin >> dest;
                if (dest == -1){
                    break;
                }
                else{
                    adj_list[vertex].push_back(dest);   
                    adj_list[dest].push_back(vertex); 
                }
            }
        
    }


    // This loop is required since there might be some nodes which are not covered 
    // if we just call DFS once i.e when the Graphs are not CONNECTED.
   for (int i=1; i<=n; i++) {
        
   // We need to ensure that all nodes are visited.
        if (traversalColor[i] == 0) {
            DFS(i); 
        }
    }
    
    return 0;
}
