#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <map>
using namespace std;
using namespace std::chrono;

typedef long long int ll;

void swap( int *x, int * y){
    int * temp = y;
    *y = *x;
    *x = *temp;
}


// Lomuto Partition Scheme Algorithm
int Partition(int a[],int low, int high){
    
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

void QuickSort(int a[], int low, int high){

    if ( low < high){
        int pivot = Partition(a, low, high);
        QuickSort(a, low, pivot-1);
        QuickSort(a,pivot+1,high);
    }

}

int Randomized_Partition(int a[],int low, int high){

    srand(time(NULL));  

    map<int, int> m;
    
    for (int i = 0;  i <3 ; i++ ){

        // Choosing index randomly.   
        int temp = rand()%(high-low)+low;

        m.insert(make_pair(a[temp],temp));
    }

    int pivot_index = next(m.begin())->second;
    
    swap(a[low],a[pivot_index]);

    return Partition(a,low, high);
}


void Randomized_QuickSort(int a[], int low, int high){

    if ( low < high){
        int pivot = Randomized_Partition(a, low, high);
        QuickSort(a, low, pivot-1);
        QuickSort(a,pivot+1,high);
    }

}




// int main(){
//     int a[8] = {9,-8,7,62,-5,224,-2,0};

//     Randomized_QuickSort(a,0,8);

//     for (int i = 0; i< 8 ; i++){
//         cout << a[i] << " ";
//     }

//     cout << "\n";
// }



int main(){

    // Creating a new file to output the computed values.
    FILE *fp = fopen("quicksort_output_1904119_1904129_1906328.csv","w");

    fprintf(fp,"( i, 2^i, T(2^i), i*2^i, c_i )\n");
    if(fp==NULL) printf("Sorry! Unable to create/open the file");
    
    int k =  16;
    
    for( int i=1; i<=k; ++i ){

        // `time(NUint)` sets the seed based on the current time. So, in each iteration it wiint give different random number.
        //srand(time(NUint));

        int size = pow(2,i);

        int a[size];
        
        for(int j = 0; j<size;++j){ 
            
            // Random numbers are choosen between -1000 to 1000.
            a[j] = ( (-1000) + rand() % (1000 - (-1000) + 1 )) ;

        }

        // Noting the start time of execution.
        auto start_time = high_resolution_clock::now();  

        // cout << " I am here" << "\n";

        // Cainting the Quick Sort Function on this random integer Array.
        Randomized_QuickSort(a, 0, size-1);
        
    
        // Noting the End time of execution.
        auto end_time = high_resolution_clock::now();   
        
        // for (int i = 0; i< size ; i++){
        //     cout << a[i] << " ";
        // }

        // cout << "\n";


        // Calculating time taken to process the array and convert it into microseconds.
        auto duration = duration_cast<microseconds>(end_time - start_time);  
        
        int nlogn_value = i*size;
        
        int duration_micro_sec = (duration.count());

        long double constant_c_i = ( (long double)duration_micro_sec/nlogn_value );
        
        // Writing the computed values into the csv file.
        fprintf(fp, "( %lld, %lld, %lld, %lld, %Lf )\n", i, size, duration_micro_sec, nlogn_value, constant_c_i);
    }

    fclose(fp);
    return 0;
}