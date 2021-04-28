#include <iostream>
using namespace std;

// Using Divide and Conquer Paradigm. 
// Time Complexity is O(logn)

int findPeak (int arr[], int start, int end){

    int length = ( end - start + 1);

    int mid = (start + end )/2;

    if ( (arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1])) { return arr[mid]; }

    else if (arr[mid] < arr[mid-1]) { return (findPeak(arr, start, mid-1)); }

    else { return (findPeak(arr, mid+1, end )); }


 
}

int main(){

    int arr[7] = {0,1,15,5,4,1,0};

    cout << findPeak(arr,0,6); 

}

