#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> countingSort(vector<int> &arr, int size)
{
    map<int, int> freqMap;
    // Maps are initialised with Zeroes
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        freqMap[*i]++;
    }

    int i = 0;

    for (auto it : freqMap)
    {
        int val = it.first;
        int freq = it.second;

        for (int j = 0; j < freq; j++)
            arr[i++] = val;
    }

    return arr;
}

int main()
{
    int n, temp;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    countingSort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}