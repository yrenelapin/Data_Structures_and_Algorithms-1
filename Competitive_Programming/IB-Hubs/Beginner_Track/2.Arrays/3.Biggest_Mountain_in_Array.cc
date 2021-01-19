/*
An array B with N elements is called a mountain if there is an index 'i' such that,
B[0] < B[1] < B[2] < ... < B[i], and
B[i] > B[i+1] > B[i+2] > ... > B[N-1]

Given an array A with N elements, there are multiple subarrays in A that forms a mountain. Write a program to return the length of the biggest mountain in A.

Input
First line contains a single integer N.
Second line contains N space separated integers of A.

Output
Print a single integer representing the length of the biggest mountain.
*/


// TWO PASS APPROACH


#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b ;  } // If a>b It returns a else returns b.



int length_of_biggest_mountain(int A[], int N)
{   
    /*
    we have a uphill_array of length N where an element at index k represents the uphill length till that index in A 
    and a downhill_array of length N where an element at index K represents the downhill length from that index in A.
    */
    int uphill_array[N], downhill_array[N];
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        uphill_array[i] = 0;
        downhill_array[i] = 0;
    }

    for (int i = N - 2; i >= 0; --i)
    {
        if (A[i] > A[i + 1])
            downhill_array[i] = downhill_array[i + 1] + 1;
    }
    for (int i = 0; i < N; ++i)
    {
        if (i > 0 && A[i] > A[i - 1])
            uphill_array[i] = uphill_array[i - 1] + 1;
        if (uphill_array[i] && downhill_array[i])
            result = max(result, uphill_array[i] + downhill_array[i] + 1); // Very Useful Syntax for finding Max in array's
    }
    return result;
}

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    printf("%d", length_of_biggest_mountain(A, N));
    return 0;
}