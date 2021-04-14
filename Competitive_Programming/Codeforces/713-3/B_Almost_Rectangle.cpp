#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  
  char c;

  map < pair<int,int>, int > points;
  int x1,y1,x2,y2;
  int a = 0;
  for (int i = 0;  i <n ; i++){
      for (int j = 0;  j <n ; j++){
            cin >> c;
            if (c == '*'){
                a++;
                points[{i,j}]++;
                if (a==1){
                    x1  = i;
                    y1  = j;
                }
                else{
                    x2  = i;
                    y2 = j;
                }

            }
      }
  }
    

    // Same Row
   if (x1 == x2){

       // Top Most
       if (x1 ==0){
           points[{ x1+1, y1}]++;
           points[{ x2+1, y2}]++;
           
       }

       // Bottom Most 
       else if (x1 == n-1){
           points[{ x1-1, y1}]++;
           points[{ x2-1, y2}]++;
           
       }

       else {

           points[{ x1-1, y1}]++;
           points[{ x2-1, y2}]++;
           

       }

   } 

   
   //  Same Column
   else if (y1 == y2){

       // Top Most
       if (y1 ==0){
           points[{ x1, y1+1}]++;
           points[{ x2, y2+1}]++;
           
       }

       // Bottom Most 
       else if (x1 == n-1){
           points[{ x1, y1-1}]++;
           points[{ x2, y2-1}]++;
           
       }

       else {

           points[{ x1, y1-1}]++;
           points[{ x2, y2-1}]++;
           

       }

   }
   else{ 

        points[{ x1, y2}]++ ;       
        points[{ x2, y1}]++ ;       
        
    }


    // cout << "here" << endl;
    for (int i = 0;  i <n ; i++){
      for (int j = 0;  j <n ; j++){
           if (points[{i,j}] == 1){
               cout << "*" ;
           }
           else{
               cout << ".";
           }
      }
      cout << endl;
    }

    

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