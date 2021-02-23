#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void max_heapify(int arr[], int m, int n)
{
    int largest = m;
    int left = m * 2 + 1, right = m * 2 + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != m)
    {
        swap(arr[m], arr[largest]);
        max_heapify(arr, largest, n);
    }
}

void build_maxheap(int arr[], int n)
{
    for (int k = (n / 2) - 1; k >= 0; k--)
        max_heapify(arr, k, n);
}


void heapsort(int a[], int N){
    build_maxheap(a, N);
    for (int i = N-1 ; i > 0 ; i--){
        swap(a[0], a[i]);
        max_heapify(a,0,i);
    }
}

int main()
{
    int N = 20;
    int A[N];

    srand(time(NULL));
    for(int j = 0; j<N;++j){ 

        // Random numbers are choosen between -1000 to 1000.
        A[j] = ( (-1000) + rand() % (1000 - (-1000) + 1 )) ;
    }

    heapsort(A, N);

    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
      
    }
    return 0;
}