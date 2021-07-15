/*
Optimal Allocation of Doctors
A hospital has N rooms numbered 1 to N where each room is connected to every other room (need not be a direct connection),
and the distance between any two adjacent rooms is one unit.

The hospital management has decided to allocate the minimum number of doctors such that patients in every room are treated.

A doctor with strength zero can only take care of the allocated room. Similarly, a doctor with strength K can take care of the allocated room as well as the rooms which are within K units (inclusive) away from this room.

The manager has allocated M doctors to rooms and requested you to verify if the allocation is optimal. So, write a program to check if the allocation is a optimal one.

Note: Optimal allocation means doctors are placed in a way such that a room can be accessible to only one doctor and also no room is left inaccessible.

Input
First line contains two space separated integers N and M.
In each of the next N lines, the first integer has an edge with all the following integers except last one. -1 at the end represents end of line.
In each of the next M lines contain two space separated integers, the first integer represents the room the doctor has been allocated, and the second integer represents the strength of the doctor.

Output
Print 'Yes', if the allocation is optimal, otherwise, print 'No' (both without quotes).

Constraints
1 <= N <= 1000
1 <= M <= 1000
*/

#include <bits/stdc++.h>
using namespace std;
int n = 1005;
vector<vector<int>> adj_list(n+1);
vector<bool> visited(n+1, false);
vector<int> distance_vec(n+1);
vector<pair<int,int>> doctors(n+1);
queue<int> q; 

void BFS(int vertex, int strength, bool& fine){
    // This is sufficient to make sure that other doctors 
    // did not cover the rooms that I can cover.
    if (visited[vertex]){
        fine = 0;
        return;
    }

    distance_vec[vertex] = 0;
    visited[vertex] = true;
    q.push(vertex);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(auto v: adj_list[curr]){
            
            if (!visited[v]){
                
                distance_vec[v] = 1 + distance_vec[curr];
                
                // If the room is within the limits of the doctor,
                // then only I can visit & hence then only we push to queue.
                if (distance_vec[v] <= strength){
                    visited[v] = true;
                    q.push(v);
                }
                
            }
        }
    }
}

int main() {
    int m; cin >> n >> m;
    int vertex, destination;
    for (int i = 0; i < n; i++){
            cin >> vertex;
            while(1){
                cin >> destination;
                if (destination == -1) break;
                adj_list[vertex].push_back(destination);   
                adj_list[destination].push_back(vertex);  
            }
    }
     for (int i = 0; i < m; i++){  // room, strength
         cin >> doctors[i].first >> doctors[i].second;
         
         bool fine = 1;
         BFS(doctors[i].first, doctors[i].second, fine);
         
         // Since we need to calculate the distances from each
         // doctor's node during BFS, we reinitialise to 0.
         distance_vec = vector<int>(n+1);
         
         if (!fine){
             cout << "No";
             return 0;
         }
     }
     
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
             cout << "No";
             return 0;
        }
    }
    
    cout << "Yes";
    return 0;
}