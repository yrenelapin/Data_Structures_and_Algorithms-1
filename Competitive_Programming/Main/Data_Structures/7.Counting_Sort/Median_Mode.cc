#include <iostream>
#include <algorithm>
using namespace std;

void mode_median_of_array(int arr[], int n)
{
    int max, mode, temp_arr[n];

    // store frequency of each element
    max = *max_element(arr, arr + n);
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // mode is the index with maximum count
    mode = distance(count, max_element(count, count + max + 1));

    // modify count array to prefix sum array
    for (int i = 1; i < max + 1; i++)
        count[i] = count[i] + count[i - 1];

    // add elements into temp_arr in sorted order
    for (int i = 0; i < n; i++)
        temp_arr[--count[arr[i]]] = arr[i];

    // print mode and median
    if (n % 2 != 0)
        printf("%d %.1lf\n", mode, (double)temp_arr[n / 2]);
    else
        printf("%d %.1lf\n", mode, (temp_arr[(n - 1) / 2] + temp_arr[(n / 2)]) / 2.0);

    return;
}

int main()
{
    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        mode_median_of_array(arr, N);
    }

    return 0;
}
