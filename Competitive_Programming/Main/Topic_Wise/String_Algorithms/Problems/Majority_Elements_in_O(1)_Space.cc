/*
Majority Elements
You are given a string S of N size, find all the elements that appear more than ⌊ N/3 ⌋ times.

Note: Try to solve it in O(1) space and linear time.
Note: All strings consist of only lowercase English letters.

Input
The input contains a string S.

Output
The output contains the characters that satisfy the above condition in the lexicographical order.
If there are no such characters print -1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<char> majority_element(vector<char> &str)
{
    int cnt1 = 0, cnt2 = 0;

    // There can at most be two characters that satisfy the condition. This is the crucial Observation to be able to solve in O(1) SPACE.
    char a = '*', b = '*';

    /* 
    This loop gives two characters which have a count more than n / 3 (if they exist).
    More precisely, once this loop exits, we have top two most frequent characters from the given string stored in a,b.
    */
    for (auto c : str)
    {
        if (a == c)
        {
            cnt1++;
        }
        else if (b == c)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            a = c;
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            b = c;
            cnt2 = 1;
        }
        else
        {   // Since there can be only 2 such elements that satisfy given conditions,
            // The below increments makes sure that the element which has less frequency among a,b will be updated with the new element 
            // if its freq is more.
            // To understand the flow, dry run with some examples.
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for (auto c : str)
    {
        if (c == a)
            cnt1++;
        else if (c == b)
            cnt2++;
    }

    vector<char> res;
    if (cnt1 > str.size() / 3)
        res.push_back(a);
    if (cnt2 > str.size() / 3)
        res.push_back(b);
    return res;
}

int main()
{
    string s;
    cin >> s;
    vector<char> str(s.begin(), s.end());
    vector<char> res = majority_element(str);
    sort(res.begin(), res.end());
    for (auto i : res)
        cout << i << " ";
    if (res.size() == 0)
        cout << -1;
}