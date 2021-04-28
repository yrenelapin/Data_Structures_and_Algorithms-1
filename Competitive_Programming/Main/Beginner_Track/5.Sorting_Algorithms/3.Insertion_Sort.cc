#include <iostream>
using namespace std;

void swap(int *p1 , int *p2 ){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 
}

void Insertion_Sort(int array[], int N){

    for (int i = 0; i<N; i++){
            int key = array[i] ;
            int j = i- 1;
            while ( (j >= 0)  && (key <array[j]) ){
                array[j+1] = array[j];
                j-=1;
            } 
            array[j+1] = key;
    }

}

int main(){
    const int N = 7;
    int array[N] = {4,3,2,2,1,6,5};
    Insertion_Sort(array,N);
    for (int i = 0; i<N; i++){
    printf("%d ",array[i]);}

}