#include <iostream>
using namespace std;

void swap( int *x, int * y){
    int * temp = y;
    *y = *x;
    *x = *temp;
}


////////////////////////////////////////////////////////////////

// Lomuto Partition Scheme Algorithm
int partition_LPS(int a[],int low, int high){
    
    int piv = a[high];
    int i = low -1 ;
    for (int j = low ; j < high; j++){
        if (a[j] <= piv){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;

}


void QuickSort_LPS(int a[], int low, int high){

    if ( low < high){
        int pivot = partition_LPS(a, low, high);
        QuickSort_LPS(a, low, pivot-1);
        QuickSort_LPS(a,pivot+1,high);
    }

}

////////////////////////////////////////////////////////////////

// Hoare's Classic Partitioning Algorithm
int partition_HCP(int a[],int low, int high){
    
    int piv = a[low];
    int i = low -1 ;
    int j = high + 1;

    while (true){

    do{ i++;
    } while(a[i] < piv);

    do{ j--;
    } while(a[j] > piv);

    if ( j > i){
        swap(a[i], a[j]);
    }
    else{
        return j;
    }
}

}


void QuickSort_HCP(int a[], int low, int high){

    if ( low < high){
        int pivot = partition_LPS(a, low, high);
        QuickSort_LPS(a, low, pivot);   // We include Pivot also.
        QuickSort_LPS(a,pivot+1,high);
    }

}


////////////////////////////////////////////////////////////////



int main(){
    int a[5] = {2,13,1,3,5};

    QuickSort_LPS(a,0,4);

    for (int i = 0; i< 5 ; i++){
        cout << a[i] << " ";
    }

    cout << "\n";

    int b[5] = {21,13,11,23,50};

    QuickSort_HCP(b,0,4);

    for (int i = 0; i< 5 ; i++){
        cout << b[i] << " ";
    }

}