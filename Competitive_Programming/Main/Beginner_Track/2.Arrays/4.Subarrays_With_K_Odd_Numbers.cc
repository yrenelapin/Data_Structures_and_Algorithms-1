/*
Given an array A of N integers and an integer K, write a program to find the number of subarrays in A with exactly K odd numbers in them.

Input
First line contains two space separated integers N and K.
Second line contains N space separated integers of A.

Output
Print a single integer representing the number of such subarrays based on the above context.
*/


// SLIDING WINDOWS APPROACH

#include <iostream>
#include <vector>

using namespace std;

int at_most_odds(vector<int> &arr, int k)
{
    int ans = 0, left = 0, evenCounter = 0, n = arr.size();
    for (int right = 0; right < n; right++)
    {
        evenCounter += arr[right] % 2;
        while (evenCounter > k)
        {
            evenCounter -= arr[left] % 2;
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int num_of_sub_arrays(vector<int> &arr, int k)
{
    return at_most_odds(arr, k) - at_most_odds(arr, k - 1);
}

int main()
{
    int n, k, input;
    cin >> n >> k;
    vector<int> arr;
    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }
    cout << num_of_sub_arrays(arr, k);
    return 0;
}