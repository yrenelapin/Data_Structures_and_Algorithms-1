#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli isPalindrome(string str) 
{ 
    
    lli l = 0; 
    lli h = str.size() - 1; 
  
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return 0; 
        } 
    } 

    return 1;

}

lli check_match(string str, int k){
    
    lli l = 0; 
    lli h = str.size() - 1; 
  
    while (l < k) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return 0; 
        } 
    } 

    return 1;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    lli t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;

        if (k==0) {cout << "YES\n"; continue;}
        if (isPalindrome(s)){
            if ((2*k+1) > n ){cout << "NO\n"; continue;}
            cout << "YES\n";
        }
        else{
            if (check_match(s, k)) {cout << "YES\n"; }
            else { cout << "NO\n"; }
        }

    }

    return 0;
}