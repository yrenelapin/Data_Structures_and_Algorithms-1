// Ref:  https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;


// We use DFS approach.
bool check_cycle(int vertex,   vector < vector<int> > graph, vector<bool> &visited, vector<bool> &recursion_stack)
{
    visited[vertex] = true;
    recursion_stack[vertex] = true;
    
    for (auto i : graph[vertex])
    {   
        // If a node is not visited, We insert it to stack & make a recursive call again.
        if (!visited[i] && check_cycle(i, graph, visited, recursion_stack))
        {
            return true;
        }
        
        // If the node is visited, We will check if it is on recursion stack.
        else if (recursion_stack[i])
            return true;
    }
    
    // vertex is removed from stack as in usual DFS.
    recursion_stack[vertex] = false;
    
    // If no such cycle is found, return false.
    return false;
}

string check_cycle(  vector < vector<int> > graph, int len)
{
    vector<bool> visited(len, false);
    vector<bool> recursion_stack(len, false);
    
    // This loop helps incase of Disconnected Graphs.
    for (int i = 1; i < len; i++)
    {   if (!visited[i]){
            if (check_cycle(i, graph, visited, recursion_stack))
            {
                return "Yes";
            }
        }   
    }
    return "No";
}


int main()
{
    int n, source, dest;
    cin >> n;

    vector < vector<int> > adj_list(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> source;
        while (1)
        {
            cin >> dest;
            if (dest == -1)
                break;
            adj_list[source].push_back(dest);
        }
    }

    cout << check_cycle(adj_list, n+1);
    return 0;
}