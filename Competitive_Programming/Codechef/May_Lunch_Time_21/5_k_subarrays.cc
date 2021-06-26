#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 1e18;
 
vector< vector<int> > dp(100010, vector<int> (110, -inf));
vector< vector<int> > prefix(100010, vector<int> (110, -inf));
 
void solve()
{
    int n, k;
	cin >> n >> k;
	int a[n];
 
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	// BASE CASE-1
	for(int i=0; i<n; i++){
	   // If zero sub arrays are made, the maxmimum score is 0. 
       dp[i][0] = 0;
       prefix[i][0] = 0;
	}

	// BASE CASE-2
	// Considering only the 1st element is taken and only 1 subarray has been formed till now.
	dp[0][1] = a[0]*1;

	// To store the maximum value, we initialise with dp[0][1]
	prefix[0][1] = dp[0][1];
 
	// Filling the dp[N][K] in bottom up manner.

	for(int i=1; i<n; i++){

		for(int j=1; j<=k; j++){

      		// This includes both the possibilities at once. 
			// dp[i-1][j] indicates the case where we take the ith element into the jth subarray.
			// prefix[i-1][j-1] indicates the case where we start a new subarray j from this ith element.
			dp[i][j] = max(dp[i-1][j], prefix[i-1][j-1]) + a[i]*j;

			// This is for updating the prefix array.
			prefix[i][j] = max(prefix[i-1][j], dp[i][j]);
		}
	}
 
	int ans = -inf;

	// We will find the maximum among all the cases of making
	// k subarrays where kth subarray can end at any location.
	for(int i=0; i<n; i++){
		ans = max(ans, dp[i][k]);
	}
 
	cout << ans << "\n";
}
 
int32_t main(){
  // freopen("sub5.in","r",stdin);
  // freopen("sub5.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
 
  while(t--)
  {
    solve();
  }
 
return 0;
}

// Refer Editorial for more explanation : https://discuss.codechef.com/t/chesub-editorial/90440