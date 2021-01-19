#include <iostream>
using namespace std;

void swap(int *p1 , int *p2 ){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 
}

void Bubble_Sort(int array[], int N){

    for (int i = 0; i<N; i++){
            bool swapped = false;
            for (int j = 0 ; j<N-1 ; j++){
                if (array[j] > array[j+1]) 
                { swap(&array[j], &array[j+1]);
                   swapped = true; 
                } 
            }
            N= N-1 ;
            if (swapped == false ) break;
            

    }

}

int main(){
    const int N = 7;
    int array[N] = {4,3,2,2,1,6,5};
    Bubble_Sort(array,N);
    for (int i = 0; i<N; i++){
    printf("%d ",array[i]);}

}