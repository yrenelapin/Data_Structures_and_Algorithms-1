#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
  
  int n;
  cin>>n;

  int a[2*n];
  for(int i =0; i<2*n; i++){

    cin>>a[i];

  }

  map<int,int> mp;

  for(int i =0; i<2*n; i++){
    mp[a[i]]++;
  }
  
  for(auto i : mp){

    if(i.first%2 ==1 || i.second !=2){
      cout<<"NO"<<endl;
      return;
    }
  }

  vector<int> v;
  for(auto i : mp){
    int val = i.first/2;
    int fre = i.second/2;

    for(int j =0; j<fre; j++){
      v.push_back(val);
    }
  }
 
  sort(v.begin(),v.end());
  set<int> s;

  int sum =0;
  bool flag = true;
  for(int j = n-1; j>=0; j--){

    int y = (v[j]-sum)/(j+1);
    int rem = (v[j]-sum)%(j+1);
    if(s.find(y)!=s.end() || rem!=0 || y<=0){
      cout<<"NO"<<endl;
      return;
    }
    else {

      s.insert(y);
      sum+=y;
    }
  }

  cout<<"YES"<<endl;
}







int32_t main(){
  int t;
  cin>>t;
  while(t--){


    solve();
  

  }

}