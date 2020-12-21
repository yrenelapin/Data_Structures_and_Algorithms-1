#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr_x,int *ptr_y){
    int temp = *ptr_y ;    
    *ptr_y = *ptr_x ;
    *ptr_x = temp; 
}

void quickSort(int *arr, int start, int end)  
{  
    if (start < end)  
    {  
        
            int pivot = arr[end];      
            int i = (start - 1);     
        
            for (int j = start; j <= end - 1; j++)  
                {  
                
                    if (arr[j] < pivot)  
                    {  
                        i++; 
                        swap(&arr[i], &arr[j]);  
                    }  
                }  

            swap(&arr[i + 1], &arr[end]);  
            
            int pivot = (i + 1);  

        quickSort(arr, start, pivot - 1);  
        quickSort(arr, pivot + 1, end);  
    }  
}  
  



int main(){

    int data[] = {4,3,1,2,11,22,12,6};

    int N = sizeof(data)/sizeof(data[0]);

    int *arr = data;

    quickSort(arr,0,N-1);

    printf("The Sorted Array is :- \n");
    
    for (int j = 0 ; j< N ; j++ ){
        printf("%d ",arr[j]);
    }        

}