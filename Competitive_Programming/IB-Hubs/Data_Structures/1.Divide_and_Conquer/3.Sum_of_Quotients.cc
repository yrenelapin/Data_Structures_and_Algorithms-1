#include <iostream>
using namespace std;

long long int sum_of_quotitents(int a[], int n,int s){
    
    int maxi =  -10^9 ;
    for (int i = 0; i< n; i++ ){
        maxi =  max(maxi , a[i]);
    }
    int low = 1 ;
    int high = maxi +1 ;
    int x = high ;
    while (high >= low){
            int mid  = ( low + high )/2 ;
            
            long long int sum = 0 ;
            for (int i = 0 ; i<n; i++ ){
                sum += (a[i]/mid);
            }
    
            if (sum > s){
                low = mid+1;}
            else {
                x = min(x, mid);
                high = mid-1;
            }
    }
    return x;
}

int main(){
     int n, s;
    cin >> n >> s ;
     int a[n];
    for (int i = 0 ; i< n; i++){
        cin >> a[i];
    }
    
    cout << sum_of_quotitents(a, n, s);
    
}