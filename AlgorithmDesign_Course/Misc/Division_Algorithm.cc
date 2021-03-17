#include <bits/stdc++.h>
using namespace std;

vector<int> divide(int x,int y){
    vector<int> v ;

    if (x == 0){
        v.push_back(0); v.push_back(0);
        // cout << "Quotient = " << v[0] << "   Remainder = " << v[1]  << endl ; 
        return v;
    }

    else{
        auto temp = divide(x/2, y);
        temp[0] = 2*temp[0];
        temp[1] = 2*temp[1];

        if ( x %2 == 1){
            temp[1]++;
        }   

        if (temp[1] >= y){
            temp[1] -= y;
            temp[0]++;
        }

        // cout << "Quotient = " << temp[0] << "   Remainder = " << temp[1]  << endl ; 
        return temp;
    }


}

int main(){
    int x = 22;
    int y = 3;
    auto result = divide(x,y);
    cout << "Quotient = " << result[0] << "   Remainder = " << result[1] ; 
}
