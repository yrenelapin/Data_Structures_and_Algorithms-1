#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long int ull ;

ull give_3(int place, ull max){
       ull lower = pow(10,place-3);
       ull temp =  (max/ lower);
       ull temp_2 = pow(10,3);
       return (temp % temp_2) ;
}

int check_all(int place, vector<ull> v){
     
     for(int j = 0 ; j < v.size() ; j++){  
        ull temp = v[v.size()-1-j];
        if (give_3(place,temp)){
            return 1;
    }

   }
    return 0;
}

void countingSort(ull array[], int size, int place)
{
    ull max = 1000, output[size], count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++){
        count[give_3(place, array[i])]++;  // Taking the digit in the Place
        }
        
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--){
        output[--count[give_3(place, array[i])]] = array[i];}

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}


    
bool isgreater(int i , int j){
    return (i > j);
}

void radixsort(ull array[], int size)
{   
    ull max = *max_element(array, array + size);
    int place; 
    
    vector<ull> v;
    for (int i = 0;i < size ; i++){
        v.push_back(array[i]);
    }
    
    sort(v.begin(), v.end());

    for (place = 3; check_all(place,v) != 0 ; place += 3){
        
        ull copy[size];
        for (int i = 0; i < size; i++){
            copy[i] = array[i];
        }
        
        countingSort(copy, size, place);
        for (int i = 0; i < size; i++)
            { cout << copy[i] << " ";}
        cout << "\n";
    }
    
}



int main()
{
    int N;
    cin >> N;
    ull array[N];
    for (int i = 0; i < N; i++)
        cin >> array[i];

    radixsort(array, N);
    return 0;
}