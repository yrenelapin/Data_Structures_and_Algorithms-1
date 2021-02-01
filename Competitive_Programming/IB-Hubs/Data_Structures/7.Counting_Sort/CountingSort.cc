#include <iostream>
using namespace std;

void counting_sort(int array[], int output_array[],int max, int n){

    int count_array[(max+1)];
    
    for (int i = 0; i< max+1; i++){
        count_array[i] = 0;
    }  

    for (int j = 0; j< n; j++){
        count_array[array[j]]++;
    }

    for (int k = 0; k< max+1; k++){
        count_array[k]+=count_array[k-1];
    }

    for (int a = 0; a<n; a++){

        count_array[array[a]]--;
        output_array[count_array[array[a]]] = array[a];
    }
    
}

int main(){
    
    int a[7] = {4,2,2,8,3,6,1};
    int max = 8;
    int out[7];
    counting_sort(a,out,max,7);

    for (int i = 0; i< 7 ; i++){
        cout << out[i] << " ";
    }

}