#include <iostream>
using namespace std;

void swap(int *p1 , int *p2 ){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 
}

void Selection_Sort(int array[], int N){

    for (int i = 0; i<N; i++){
        int min = i ;
        for (int j = i ; j<N ; j++){
            if (array[min] > array[j]) min = j;
        }
        swap(&array[i], &array[min]); 

    }

}

int main(){
    const int N = 7;
    int array[N] = {4,3,2,2,1,6,5};
    Selection_Sort(array,N);
    for (int i = 0; i<N; i++){
    printf("%d ",array[i]);}

}