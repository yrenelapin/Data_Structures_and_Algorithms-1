/*
Word Transformation
Given two words (A and B), and a sequence P of N words, find the number of transformations needed for A to become B.

A transformation from a word is defined as:
- Only one letter can be changed at a time

A transformation path is a sequence of words from A to B such that all the transformation words are present in the P.

Note: All strings consist of only lowercase English letters.

Input
The first line of input contains a string A.
The second line of input contains a string B.
The third line of input contains an integer N.
The fourth line of input contains N space-separated strings.
Output
The output contains two integers, the first representing the number of possible solutions and the second representing the transformation length.
The two integers are separated by space.
If there is no possible transformation path print -1.
Note: Consider only the transformation paths of shortest length in the output.

Constraints
2 <= A.length <= 4
2 <= B.length <= 4
1 <= N <= 2 * 10^5
*/

// Ref: https://leetcode.com/problems/word-ladder/submissions/


#include <bits/stdc++.h>
using namespace std;

string a,b;
int n = 200005;
vector<string> p(n);
unordered_map<string, vector<string>> adjhelper;
unordered_map<string, int> distances, noofpaths;

void preprocess(){
    for(auto word: p){
        distances[word] = INT_MAX;
        for(int i = 0; i <word.size(); i++){     
            string inter =  word.substr(0,i) + "*" +  word.substr(i+1);
            adjhelper[inter].push_back(word);
        }
    }
}

int BFS(){
    queue< string> myqueue;
    unordered_map<string, int> visited;
    visited[a] = 1;
    distances[a] = 0;
    noofpaths[a] =  1;
    myqueue.push(a);

    while(!myqueue.empty()){
        string currword = myqueue.front();
        int currdist = distances[currword];  
        myqueue.pop(); 

        if (currword == b){
            // Since we need no of nodes in the path, we add 1.
            return currdist + 1;
        }
        
        for(int i = 0; i <currword.size(); i++){       
            string inter =  currword.substr(0,i) + "*" +  currword.substr(i+1);
            for(auto word: adjhelper[inter]){
                if (!visited[word]){
                    visited[word] = 1;
                    myqueue.push(word );
                }
                if ( distances[word] > distances[currword] + 1){
                          distances[word] = distances[currword]+1;
                          noofpaths[word] = noofpaths[currword];
                    }
                else if (distances[word] == distances[currword] + 1){
                       noofpaths[word] += noofpaths[currword];
                }
            }
        }
    }
    
    return 0;
}

int main(){
    cin >> a >> b;
    cin >> n;  for(int i = 0;  i<n; i++) cin>> p[i];
    preprocess();
    int res = BFS();
    if (res == -1){
        cout << res;
    }
    else{
        cout << noofpaths[b] << " " << res;
    }
	return 0;
}