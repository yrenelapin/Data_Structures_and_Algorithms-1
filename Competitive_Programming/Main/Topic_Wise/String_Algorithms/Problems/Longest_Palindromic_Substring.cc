// Longest Palindromic "Substring"
// A O(n^2) time and O(1) space program to find the longest palindromic substring
// Ref: https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

#include <iostream>
#include <vector>

using namespace std;

int longest_palindrome(string &s){  

    int n = s.size();

    if (s.empty())
        return 0;

    int min_start = 0, max_len = 1;

    // Expand around the centre to check for a palindrome
    for (int i = 1; i < s.size(); i++){

        // Find longest even length palindrome.
        int low = i-1, high = i;
        while( low >= 0 and high < n  and s[low] == s[high] ){
            if (high-low+1 > max_len){
                max_len = high-low+1;
                min_start = low;
            }
            low--; high++;
        }


        // Find longest odd length palindrome.
        low = i-1; high = i+1;
        while( low >= 0 and high < n  and s[low] == s[high] ){
            if (high-low+1 > max_len){
                max_len = high-low+1;
                min_start = low;
            }
            low--; high++;
        }
    }

    return max_len;
}

int main()
{
    string s;
    int ans;
    cin >> s;
    ans = longest_palindrome(s);
    cout << ans;
}

