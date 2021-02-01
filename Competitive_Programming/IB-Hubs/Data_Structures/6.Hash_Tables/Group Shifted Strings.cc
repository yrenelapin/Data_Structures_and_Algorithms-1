#include<vector>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

int main()
{

  int n;
  cin>>n;
  multimap<int,string> u;
  for(int i=0;i<n;i++)
   {
     string s;
     cin>>s;
     u.insert(make_pair(s.length(),s));
   }
   
   vector<int> v;

   // Iterating over all the possible String Lengths
   for(int i=1;i<=10000;i++){

     // If string with that length is found in the multimap 
     if (u.find(i)!=u.end())
      {

        auto range = u.equal_range(i);
        set<string> et;
        for(auto it=range.first;it!=range.second;it++)

          {

           string s=it->second;

           int o=s[0]-'a';

           for(int m=0;m<s.length();m++)

             { int f=s[m]-'a'-o;

               s[m]=char('a'+(26+f)%26);

             }

            et.insert(s);

          }

        v.push_back(et.size());  

      }

   }

   for(int i=0;i<v.size();i++)

    cout<<v[i]<<" ";

return 0;

}