#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef unsigned long long int ull;

int ispossible(vector<int>&v,ull mid){

  int index=0;

  int count =1;

   ull sum=0;

  while(index<v.size()){

     sum= sum+v[index];

     if(sum>mid){

       count ++;

       sum=v[index];

     }

     index++;

  }

  return count;

}

ull maxpages(vector<int>&v,int books,int stud){

  ull start=v[books-1];

  ull end=0;

  ull result=ULLONG_MAX;

   for(int i=0;i<v.size();i++){

     end+=v[i];

   }

   while(start<=end){

     ull mid= start+ (end-start)/2;

   

     int check= ispossible(v,mid);

     if(check==stud){

      
       result=min(result,mid);

       end=mid-1;

        }

     else if(check>stud){

       start=mid+1;

        }

     else if(check<stud){

       end=mid-1;

        }

      

   }

   return result;

   

   

}

int main(){

  int k,l;

  cin>>k>>l;

  vector<int>v;

  for(int i=0;i<k;i++){

    int num;

    cin>>num;

    v.push_back(num);

  }

  if (k == l){
      cout << v[k-1];
      return 0;
  }   

  ull maxi= maxpages(v,k,l);

  cout<<maxi;


}