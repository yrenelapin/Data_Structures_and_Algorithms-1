#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

typedef unsigned long long int ull;

ull CalculateRank(vector<ull> prefix, ull n, ull x) 
{ 
    ull cnt; 
  
    // Initially rank is 0. 
    ull rank = 0; 
    ull sumBeforeIthindex = 0; 
    for (ull i = 0; i < n; ++i) { 
  
        // Calculating the count the subarray with 
        // starting at ith index 
        cnt = upper_bound(prefix.begin(), prefix.end(),  
                sumBeforeIthindex + x) - prefix.begin(); 
  
        // Subtracting the subarrays before ith index. 
        cnt -= i; 
  
        // Adding the count to rank. 
        rank += cnt; 
        sumBeforeIthindex = prefix[i]; 
    } 
    return rank; 
} 
  
ull findKthSmallestSum(ull a[], ull n, ull k) 
{ 
    // PrefixSum array. 
    vector<ull> prefix; 
  
    // Total Sum initially 0. 
    ull sum = 0; 
    for (ull i = 0; i < n; ++i) { 
        sum += a[i]; 
        prefix.push_back(sum); 
    } 
  
    // Binary search on possible 
    // range i.e [0, total sum] 
    ull ans = 0; 
    ull start = 0, end = sum; 
    while (start <= end) { 
  
        ull mid = (start + end) >> 1; 
  
        // Calculating rank of the mid and  
        // comparing with K 
        if (CalculateRank(prefix, n, mid) >= k) { 
             
            // If greater or equal store the answer 
            ans = mid; 
            end = mid - 1; 
        } 
        else { 
            start = mid + 1; 
        } 
    } 
  
    return ans; 
} 
  
int main(){
    ull n, k;
    cin >> n >> k ;
    ull a[n];
    for (ull i = 0 ; i< n; i++){
        cin >> a[i];
    }
    
    cout << findKthSmallestSum(a, n, k);
    return 0;   
}