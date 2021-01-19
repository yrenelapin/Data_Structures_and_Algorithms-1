#include <iostream>
using namespace std;

// Using Divide and Conquer Paradigm. 
// Time Complexity is Theta(logn)
// Reccurence relation is T(n) = T(n/2) + Theta(1)

int power (int x,int n){

    if (n == 0) return 1;

    int sub_power = power(x, n/2);

    if (n%2 == 0) return (sub_power*sub_power);

    else {
        return (x*sub_power*sub_power);
    }
}

int main(){

    int x = 5 ;

    int n = 3 ;

    cout << power(x,n); 

}

