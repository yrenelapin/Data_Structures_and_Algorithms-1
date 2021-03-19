/*
Create Words

A string S consists of a list of words where each list starts with '{' bracket and ends with '}' bracket,
and the words within the list are separated by ',' character. You need to form all possible words by picking only one word from each list.
Consider the consecutive characters that do not belong to any list as a separate word.

Write a program to print all words that can be formed in the manner mentioned above in lexicographical order.
Note: A word can be of length one.

Input
The only line of input contains a single string S.

Output
Print space separated strings based on the above context.

Explanation
If S = '{i,j,k}z{m,n}{a}', then the all possible words are ['izma', 'izna', 'jzma', 'jzna', 'kzma', kzna']

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> results;

void make_words(vector<vector<string>> &v, string s, int i,string ch){

    s+=ch;
    
    // Required string length is formed
    if (i==v.size()) {
        results.push_back(s);
        return;
    }

    // Now send the character from the next word
    // Ex: If i==2, It means currently, the length of string is 2 & now,
    // we need to recursively travel in the next word i.e. v[2]  which is 3rd word.
    for(auto j : v[i]){

        // Increase the length of string by 1
        make_words(v,s,i+1,j);
        }
            
    }


int main(){

    string s;
    cin>>s;
    
    // Keeping a vector of vector of strings
    vector<vector<string>> v;
    vector<string> temp;
    
    string a ="";
    for(int i=0;i<s.length();i++){
        
        if( s[i]!= '{' && s[i] != '}' && s[i] !=','){
            a+= s[i];
        }

        else if(s[i]== '{'){
            
            if(a.length()!=0){
                temp.push_back(a);
                a="";
            }

            if(temp.size()!=0){
                
                v.push_back(temp);
                temp.clear();
            }
        }
        else if(s[i]==','){
            temp.push_back(a);
            a="";
        }
        else if(s[i]=='}'){
            
            if(a.length()!=0){
                temp.push_back(a);
                a="";
            }
            
            if(temp.size()!=0){
                
                v.push_back(temp);
                temp.clear();
            }
        }
    }
     if(a.length()!=0){
                temp.push_back(a);
                a="";
            }
            if(temp.size()!=0){
                
                v.push_back(temp);
                temp.clear();
            }
            
    for(int i=0;i<v.size();i++){
        // Sorting the letters of each word in the input
        sort(v[i].begin(),v[i].end());
    }
      

    for(int i=0; i<v[0].size(); i++){
        string s ="";
        make_words(v, s, 1, v[0][i]);
    }  
    
    // To print the result in lexicographic ordering.
    sort(results.begin(), results.end());
    for (auto i : results){
        cout << i << " ";
    }
}