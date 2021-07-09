#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 2 QUERIES :

1) Why DFS fails ? How to make it work ?
2) Even in BFS, One Test case Fails. How to resolve it ?

*/

bool bfs(vector<vector<ll> > &v,ll k ,vector<ll> &arr,ll n){

  vector<bool> vis(n,false);
  queue<ll> q;
  
  // Assuming k is the first node in our BFS.
  q.push(k);
  vis[k] = true;

  while(!q.empty()){
        ll temp = q.front();
        q.pop();
        
        // Cheking if there are elements adjacent to `temp`
      
            for( ll i = 0; i<v[temp].size(); i++){
               
               if (!vis[v[temp][i]]){
                    if(arr[v[temp][i]] == 0){ return true;}
                    q.push(v[temp][i]);
                    vis[v[temp][i]] = true;
               }
            }
        

     }
  return false;
}

bool DFS(int vertex,  vector< vector<int> > &adj_list , vector<bool> &visited)
{
    // cout << vertex << " ";
    if (vertex == 0){
        return true;
    }
    visited[vertex] = true;
    for (auto i : adj_list[vertex])
    {
        if (!visited[i])
        {
            DFS(i, adj_list, visited);
        }
    }

    return false;
}

int main(){
  ll n,k;
  cin>>n>>k;
  vector<vector<ll > > v(n);  // vector of vectors
  vector<ll> arr(n), visited(n);

  int is_zero = 0;
  for(ll i = 0;i < n;i++){
    cin>>arr[i];
    if (arr[i] == 0){
        is_zero = 1;
    }
  }
  
  if (is_zero == 0) {
      cout<<"No";
      return 0;
  }
  
  for (ll i = 0;i < n;i++){
      
    // We are populating each elements of `v` with its indice's adjacent elements
    if ((i + arr[i] >= 0) and (i + arr[i] <n)) v[i].push_back(i + arr[i]);
    if((i - arr[i] >= 0) and (i - arr[i] <n)) v[i].push_back(i - arr[i]);
}
    DFS(k,v, visited)? cout<< "Yes" : cout<<"No";
    // bfs(v,k,arr,n) ? cout<< "Yes" : cout<<"No";

}