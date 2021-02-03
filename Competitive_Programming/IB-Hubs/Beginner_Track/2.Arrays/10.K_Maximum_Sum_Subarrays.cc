/*
K Maximum Sum Subarrays
Given an array A of N integers, write a program to find the sums of first K non-overlapping maximum-sum-subarrays.
Non-overlapping subarray means you cannot have same element in more than one subarray. If all elements are used atleast
once or if the subarray sum is negative, take 0 as sum.

Note: The solution should be optimal, which means when two subarrays with different lengths have the same sum, 
you have to choose the subarray with minimum elements so that you can consider the spare elements for next subarray.

Input
First line contains two space separated integers N and K.
Second line contains N space separated integers of A.

Output
Print the K sums separated by space in non-increasing order.
*/


#include <climits> 
#include <iostream>
using namespace std; 
typedef long long int ll;

void k_max_sum_subarray(ll arr[], ll k, ll n) { 
    
    // Iterating till k sums are printed.
    for(ll c = 0; c < k; c++){ 
        
        ll max_sum = INT_MIN; 
        ll cur_sum = 0; 
        
        ll start = 0, end = 0, s = 0; 
        
        // This `for` loop finds the Maximum Sum Subarray along with their indices.
        for(ll i = 0; i < n; i++) { 
            cur_sum += arr[i]; 
            if (max_sum < cur_sum) { 
                max_sum = cur_sum; 
                start = s; 
                end = i; } 
            if (cur_sum <= 0){ 
                cur_sum = 0; 
                s = i + 1;} 
        } 
        
        // Once we found the Maximum sum subarray, 
        // We replace those indices with `INT_MIN` 
        // So, in the next iteration, We get 2nd Maximum
        // sum subarray, In the next to next, 3rd Maximum etc.
        for (ll l = start; l <= end; l++) 
            arr[l] = INT_MIN; 
             
        if (max_sum < 0)
            cout << 0 << " ";
        else
           cout << max_sum << " ";
        } 
        
    cout << endl; 
} 

int main() 
{ 
  ll n,k;
  cin >> n >>k;
  ll a[n];
  for(ll i=0;i<n;i++)
    cin>>a[i];
    
k_max_sum_subarray(a,k,n);   
return 0; 
} 
