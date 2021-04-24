/*
Coin Change
Your friend has given N rupees and told you to get some change for it. You have an infinite supply of M different 
valued coins, write a program to find the number of unique coin combinations that sum up to N.
Input

First line contains two space-separated integers M and N.
Second line contains M space-separated integers representing the coins.
Output

Print an integer representing the total number of unique coin combinations that sum up to N.
Explanation

In Sample Input 1, the four unique coin combinations that sum up to N are {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using COMPLETE SEARCH (Recursive BackTracking)

set<vector<ll>> result;
void unique(vector<ll> &v, vector<ll> &choosen, ll n, ll start){
    
        if (n==0){
            result.insert(choosen);
        }
        else{
            for (ll  i = start;  i < v.size(); i++){
                if (v[i] <= n){
                choosen.push_back(v[i]);
                unique(v,choosen, n-v[i], i);
                choosen.pop_back();}
            }
        }
}

ll coin_change(vector<ll> &v,int n){
    vector<ll> choosen;
    unique(v, choosen, n,0);
    return result.size();
}

int main(){
    ll m,n; cin>>m>>n;
    vector<ll> v;
    for (ll i = 0 ;i <m; i++){
        ll temp; cin >> temp;
        v.push_back(temp);
    }
    
    cout << coin_change(v,n);
}