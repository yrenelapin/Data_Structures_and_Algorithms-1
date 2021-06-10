// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;

/*
The edit distance is the minimum number of editing operations needed to `transform a string into another string` We transform 
First string to second String.

The allowed editing operations are as follows:
• insert a character (e.g. ABC → ABCA)
• remove a character (e.g. ABC → AC)
• modify a character (e.g. ABC → ADC)

Suppose that we are given a string x of length n and a string y of length m,
and we want to calculate the edit distance between x and y
*/


/*

1. Subproblem :  Edit Distance between the Prefixes (Going from Right to Left intuitively)  x[:i], y[:j]         // No of subproblems = O(n*m) 
                 Note that this can be solved using Suffixes too.
2. Guess      :   What operation to perform among 3 on first string 
3,4. Recurrence & Impl is below
5. Original Problem : Edit Distance between the x[:n], y[:m] 

Time Complexity= O(n*m)

*/

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems
	int dp[m + 1][n + 1];

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {

			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If the last character is different, consider
			// all possibilities and find the minimum
			else
				dp[i][j]
					= 1
					+ min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Remove
							dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}


int main()
{
	string str1, str2; cin >> str1 >> str2;

	cout << editDistDP(str1, str2, str1.length(),
					str2.length());

	return 0;
}


// Ref : https://www.geeksforgeeks.org/edit-distance-dp-5/