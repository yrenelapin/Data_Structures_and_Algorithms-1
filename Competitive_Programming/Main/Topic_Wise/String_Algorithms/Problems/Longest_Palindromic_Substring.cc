// Longest Palindromic "Substring"

#include <iostream>
#include <vector>

using namespace std;

int longest_palindrome(string &s)
{
    if (s.empty())
        return 0;
    if (s.size() == 1)
        return 1;

    int min_start = 0, max_len = 1;

    //Expand around the centre to check for a palindrome
    for (int i = 0; i < s.size();){

        // Check to see if there is any chance to get a bigger palindrome
        if (s.size() - i <= max_len / 2)
            break;
    
        int j = i, k = i;
        // Skip duplicate characters.
        while (k < s.size() - 1 && s[k + 1] == s[k])
            ++k;

        i = k + 1;
        while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
        {
            // Extending the scope of one position to left and right
            ++k;
            --j;
        }

        int new_len = k - j + 1;
        if (new_len > max_len)
        {
            min_start = j;
            max_len = new_len;
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

