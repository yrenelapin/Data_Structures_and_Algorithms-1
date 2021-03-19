/*
You are given a dictionary of words and several message strings.
For each message string, determine the maximum number of non-overlapping substrings you can find that are words in the dictionary.

Input
The first line contains the number of words ( N ). The next N lines contain the words.
The next line contains the total number of message strings ( T ). Next T lines contain message strings.

Output
Print an integer representing the maximum count of non-overlapping substrings based on the above context.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2)
{   // Ascending order based on 2nd values in a pair
    return p1.second < p2.second;
}

void countNonOverlaps(vector<string> &dict, string &s)
{
    vector<pair<int, int>> v;

    for (auto i : dict)
    {   
        // pos is the start index of `ith string in dict` occurence in s.  
        auto pos = s.find(i);
        while (pos != -1)
        {  
            // Make the pair of exact start & end indices of its occurence.
            v.push_back({pos, pos + i.size() - 1});
            
            // Checking the occurence of same word again
            // since the same word can occur multiple times.
            pos = s.find(i, pos + 1);
        }
    }
    
    // Sort them based on the end values. Here we are making a Greedy choice.
    sort(v.begin(), v.end(), compare);

    int end = -1;
    int count = 0;
    for (auto i : v)
    {  
        // If the start is greater than the previous end. (Ensures No Overlaps are present)
        if (i.first > end)
        {
            end = i.second;
            count++;
        }
    }

    cout << count;
}
int main()
{
    int test, no_of_word;
    cin >> test;
    vector<string> dict;
    string s;
    while (test--)
    {
        cin >> s;
        dict.push_back(s);
    }
    cin >> no_of_word;
    
    string word;
    while (no_of_word--)
    {
        cin >> word;
        countNonOverlaps(dict, word);
        if (no_of_word != 0)
            cout << "\n";
    }
}