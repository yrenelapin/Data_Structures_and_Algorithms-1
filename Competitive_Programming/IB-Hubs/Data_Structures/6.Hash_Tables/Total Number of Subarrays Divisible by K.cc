#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long int ll;

  
// Handles all the cases 
// function to find all sub-arrays divisible by k 
// modified to handle negative numbers as well 
ll subCount(ll arr[], ll n, ll k) 
{ 
    // create auxiliary hash array to count frequency 
    // of remainders 
    ll mod[k]; 
    memset(mod, 0, sizeof(mod)); 
  
    // Traverse original array and compute cumulative 
    // sum take remainder of this current cumulative 
    // sum and increase count by 1 for this remainder 
    // in mod[] array 
    ll cumSum = 0; 
    for (ll i = 0; i < n; i++) { 
        cumSum += arr[i]; 
  
        // as the sum can be negative, taking modulo twice 
        mod[((cumSum % k) + k) % k]++; 
    } 
  
    ll result = 0; // Initialize result 
  
    // Traverse mod[] 
    for (ll i = 0; i < k; i++) 
  
        // If there are more than one prefix subarrays 
        // with a particular mod value. 
        if (mod[i] > 1) 
            result += (mod[i] * (mod[i] - 1)) / 2; 
  
    // add the elements which are divisible by k itself 
    // i.e., the elements whose sum = 0 
    result += mod[0]; 
  
    return result; 
} 

int main(){
    ll t ;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll v[n];
        for (ll i = 0;  i< n ; i++){
            ll temp; 
            cin >> temp;
            v[i]=temp;
        
        }
         cout << subCount(v,n,k)<< "\n";
  
       

        
    }
}


// Refer this for more explanation : https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/