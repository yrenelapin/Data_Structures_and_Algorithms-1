#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define ll long long
const int mod = 1e9 + 7;


int a,b, A, B;

bool check_final(string s){

    return ( count(s.begin(), s.end(), '0') == A and count(s.begin(), s.end(), '1')  == B and  (s == string(s.rbegin(), s.rend())) );
}


void solve() {

 
    cin >> a >> b;  // a is 0, b is 1
    A = a;
    B = b;
    string s;
    cin >> s;

    int l = 0;
    int h =  (a+b)-1;

    int f =  s.find('?');

    // If no question marks are present.
    if ( f == -1){

                    
            if (check_final(s)){
                cout << s << endl;
                return; }
            else{
                cout << -1 << endl;
                return; }
        
    }

    // Reducing the count of 1's & 0's that are already present.
    a -= (count(s.begin(), s.end(), '0') );
    b -= (count(s.begin(), s.end(), '1') );
    


    while (h>l){

        
        if (s[l] == s[h]){

            // Both are q.
            if (s[l] ==  '?'){

                if (a >= b){

                    if (a >= 2){
                          a-=2;
                          s[l] = '0';
                          s[h] = '0';
                    }
                    else{
                        cout << -1 << endl;
                        return;
                    }
                  
                }
                else{
                    
                    if (b >= 2){
                          b-=2;
                          s[l] = '1';
                          s[h] = '1';
                    }
                    else{
                        cout << -1 << endl;
                        return;
                    }

                }
            }

            // Both are either 0's or 1's. Then we need not do anything.
            else{
                
            }

        }
        else{ 
            // They are not equal, We have 6 cases.

            // one is '?'
            if (s[l] == '?'){
                
                // ?0 case
                if (s[h] == '0'){
                    if ( a >= 1){
                        a--;
                        s[l] = '0';
                    }
                    else{
                        cout << -1 << endl;
                        return;
                    }

                }

                // ?1 case
                else{
                    
                    if ( b >= 1){
                        b--;
                        s[l] = '1';
                    }
                    else{
                        cout << -1 << endl;
                        return;
                    }

                }

            }
            else if (s[h] == '?'){

                // 0? case 
                if (s[l] == '0'){
                    if ( a >= 1){
                        a--;
                        s[h] = '0';
                    }
                    else{
                        cout << -1 << endl;
                        return;
                    }

                }
                
                // 1? case 
                else{
                    
                    if ( b >= 1){
                        b--;
                        s[h] = '1';
                    }
                    else{
                        cout << -1 << endl;
                        return;
                    }

                }


            }
            else{ // 01 or 10 case.

                cout << -1 << endl;
                return;

            }


        }
        l++;
        h--;
    }


    // Odd length string
    if ( s.size() % 2 != 0){

        if ( s[s.size()/2] == '?'){

        
                if (a == 1){

                    s[s.size()/2] = '0';

                    if (check_final(s)){
                       cout << s << endl;  return; }
                    else{
                        cout << -1 << endl;  return;}
                }   
                else if ( b==1) {

                    s[s.size()/2] = '1';

                    if (check_final(s)){
                       cout << s << endl;  return; }
                    else{
                        cout << -1 << endl;  return;}
                }   
        
                else{
                    cout << -1 << endl; return;
                }

        }
        else{
            if (check_final(s)){
                cout << s << endl; return; }
            else{
                cout << -1 << endl;  return;}
        }

      

    }
    else{

        if (check_final(s)){
            cout << s << endl;  return;}
        else{
            cout << -1 << endl;  return; }
    
    }


    cout << -1 << endl;  return;

}

int main() {
    fastIO;
    int t = 1;
    cin >> t; // Comment if only 1 testcase.
    while(t--) {
      solve();
    }

    return 0;
}