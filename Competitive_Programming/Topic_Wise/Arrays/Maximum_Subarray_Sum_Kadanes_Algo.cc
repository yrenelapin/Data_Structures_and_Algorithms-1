#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    ll sum = 0;; ll max_sum = 0;
    for (ll i = 0; i <n; i++){
        sum =  max(array[i], sum + array[i]);
        max_sum = max(sum, max_sum);
    }
    
    if (max_sum == 0){
        // This condition is helpful if We assume that an empty subarray is NOT allowed, so the maximum subarray sum is NOT always at least 0. 
        // It can be negative too.
        cout << *max_element(array, array+n) << "\n";
    }
    else { cout << max_sum << "\n"; }
    

    return 0;
}


// This is the actual Kadanes Algorithm. We assume that an empty subarray is allowed, so the maximum subarray sum is always at least 0.
//  If this is not the case, This O(n) algorithm Fails.


// int main(){

//     int array[8] = {-1, 2, 4, -3, 5, 2, -5, 2};
//     int sum = 0; int max_sum = 0;
//     for (int i = 0; i <8; i++){
//         sum =  max(array[i], sum + array[i]);
//         max_sum = max(sum, max_sum);
//     }

//     cout << max_sum << "\n";
    
// }
