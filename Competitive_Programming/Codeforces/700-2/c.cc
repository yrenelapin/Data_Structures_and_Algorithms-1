#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int main() {
 
    int n;
    cin >> n;
    int l = 1, r = n;
    
    // map<int, int> m;
 
    while (l != r) {
 
        // Mid is the Index 
        int mid = (l + r + 1) / 2;
 
        printf("? %d\n", mid);
        fflush(stdout);
        int mid_value;
        scanf("%d", &mid_value);
 
        // m.insert(make_pair(mid,mid_value));
 
        int l_value;
        if (mid-1 >= 1){
            printf("? %d\n", mid-1);
            fflush(stdout);
            scanf("%d", &l_value);}
 
        //  m.insert(make_pair(mid-1,l_value));
 
        int r_value;
        if (mid+1 <= n){
            printf("? %d\n", mid+1);
            fflush(stdout);
            scanf("%d", &r_value);
        }
 

  
       if (( mid_value < r_value ) && (mid_value < l_value)){
            printf("! %d\n", mid);
            fflush(stdout);
            return 0;
        }
 
        if ( mid_value > l_value )
            {r = mid - 1;}
        else
            {l = mid;}
    }
 
    return 0;
}