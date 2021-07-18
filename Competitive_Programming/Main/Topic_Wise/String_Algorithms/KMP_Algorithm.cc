/*
Given a text T and a Pattern P, We need to find the start indices of all the occurences of the pattern P in the text T. 
*/

#include <bits/stdc++.h>
using namespace std;

/*
References for understanding in addition to ibhubs content:
https://youtu.be/BXCEFAzhxGY
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

// Fills lps[] for given patttern pat[0..m-1] in O(m)
// lps indicates longest proper prefix which is also suffix. A proper prefix is prefix with whole string not allowed.
void computeLPSArray(string pat, int m, vector<int> &lps){

	// length of the previous longest prefix suffix
	int len = 0;
	lps[0] = 0;

	int i = 1;
	while (i < m) {

		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if (len != 0) {
				len = lps[len - 1];
				// Note that we do not increment i here
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}


// The time complexity of KMP algorithm is O(n) in the worst case.
void KMPsearch(string pat, string txt){

    int m = pat.size(), n = txt.size();

	vector<int> lps(m);
	computeLPSArray(pat, m, lps);

	int i = 0; // index for txt
	int j = 0; // index for pat
	while (i < n) {

		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == m) {
			cout << "Found pattern at index " <<  i - j  << endl;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < n && pat[j] != txt[i]) {

			// Do not match lps[0..lps[j-1]] characters, they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}


int main(){
    string pat = "abc", txt = "abcabaabcabac";
	KMPsearch(pat, txt);
	return 0;
}