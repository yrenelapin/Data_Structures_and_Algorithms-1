#include <iostream>
using namespace std;

string query(int x)
{	
	{
		printf("%d\n", x);
		fflush(stdout);
        string s;
        cin >> s;   
        return s;
	}
}
 
int main()
{
	int L = 1, R = 1000000;
	while (L != R)
	{
		int m = (L + R + 1 ) / 2;

		string res = query(m);

        if (res == "<")
			R = m-1;
		else
			L = m;
	}
	printf("! %d\n", L);
	fflush(stdout);
	return 0;
}