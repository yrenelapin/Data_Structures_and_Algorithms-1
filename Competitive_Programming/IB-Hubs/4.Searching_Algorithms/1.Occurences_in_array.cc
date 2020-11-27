/*
Find Occurrences of K

Given an array A of N integers and a target integer K, A is sorted in non-decreasing order. 
Write a program to print the occurrences (frequency) of K in A. Print -1 if K is not found in A.

Input

First line contains a single integer N.
Second line contains N space separated integers of A.
Third line contains a single integer K.
*/


#include <iostream>
using namespace std;

// BINARY SEARCH APPROACH

void find_count(int A[], int n, int target)
{
    int low = 0, high = n - 1;
    int start_index = -1, end_index = -1;

    // Search for start index
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (A[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    if (A[low] != target)
    {
        cout << -1;
        return;
    }
    else
    {
        start_index = low;
    }

    // Search for end index
    high = n - 1;                       // We don't have to set low to 0.
    while (low < high)
    {
        int mid = (low + high) / 2 + 1;
        if (A[mid] > target)
            high = mid - 1;
        else
            low = mid;
    }
    end_index = high;

    cout << end_index - start_index + 1;
    return;
}

int main()
{
    int N, target;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> target;

    find_count(arr, N, target);
    return 0;
}
