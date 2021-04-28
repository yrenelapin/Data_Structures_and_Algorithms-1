/*
Subarrays with Sum Divisible by K
Given an array A of N integers and an integer K, write a program to print the number of subarrays in A whose sum is divisible by K.

Input
First line contains two space separated integers N and K.
Second line contains N space separated integers of A.

Output
Print a single integer representing the number of subarrays whose sum is divisible by K.
*/




#include <iostream>
#include <vector>

using namespace std;

int count_sub_arrays_div_by_k(vector<int> arr, int k)
{
    vector<int> counter(k, 0);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        counter[sum % k]++;
    }
    int ans = 0;
    for (auto x : counter)
        ans += x * (x - 1) / 2;
    ans += counter[0];
    return ans;
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
    cout << count_sub_arrays_div_by_k(arr, k);
    return 0;
}
