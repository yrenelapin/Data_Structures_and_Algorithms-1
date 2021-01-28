#include <iostream>
using namespace std;

void heapify(int arr[], int m, int n)
{
    int smallest = m;
    int left = m * 2 + 1, right = m * 2 + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != m)
    {
        swap(arr[m], arr[smallest]);
        heapify(arr, smallest, n);
    }
}

void build_minheap(int arr[], int n)
{
    for (int k = (n / 2) - 1; k >= 0; k--)
        heapify(arr, k, n);
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    build_minheap(A, N);

    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
            cout << A[i] << " ";
        else
            cout << A[i];
    }
    return 0;
}