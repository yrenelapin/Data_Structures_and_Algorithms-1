#include <iostream>
#include <vector>

using namespace std;

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

bool repeated_substring_pattern(string &s){
    int m = s.size(); vector<int> lps(m); computeLPSArray(s, m, lps);
    
    // If lps[m-1] == 0, It means no prefix whoch is same as suffix exists, so answer is false.
    // If lps[m-1] > 0 and length of remaining string (n-lps[m-1]) is dividing m, It means str[0,..lps[m-1]-1] is the substring being repeated.
    // To get better intution, dry run with few examples :)
    if (lps[m-1] > 0 and m % (m-lps[m-1]) == 0 ){
        return true;
    }

    return false;
}

int main()
{
    int T;
    cin >> T;
    string s;
    while (T--)
    {
        cin >> s;
        if (repeated_substring_pattern(s))
            cout << "YES ";
        else
            cout << "NO ";
    }
}