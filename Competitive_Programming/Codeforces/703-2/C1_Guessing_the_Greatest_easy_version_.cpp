#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl

typedef long long int ll;

const int MAXN = 100010;
 
int n;
int a[MAXN];
 
int query(int x)
{
	if (1 <= x && x <= n)
	{
		printf("? %d\n", x);
		fflush(stdout);
		scanf("%d", &a[x]);
	}
}
 
int main()
{    fastIO
	scanf("%d", &n);
	a[0] = a[n + 1] = n + 1;
	int L = 1, R = n;
	while (L < R)
	{
		int m = (L + R) / 2;
		query(m);
		query(m + 1);
		if (a[m] < a[m + 1])
			R = m;
		else
			L = m + 1;
	}
	printf("! %d\n", L);
	fflush(stdout);
	return 0;
}