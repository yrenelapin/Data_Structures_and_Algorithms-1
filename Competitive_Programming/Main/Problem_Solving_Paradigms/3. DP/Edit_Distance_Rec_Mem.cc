#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll>	vl;
typedef vector<pi>	vpi;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef priority_queue<ll> prq;  // Max priority Queue.
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T mpow(T x, T n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;
const long long INF = 1e18;

//------------------------------------------------------------------------------------------------------------------------------------//


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


int minDis(string s1, string s2, int n, int m, vector<vector<int>> &dp){
		
 	// If first string is empty, only option is to
	// insert all characters of second string
    if(n==0) return m;  
    
    // If second string is empty, only option is to
    // remove all characters of second string
    if(m==0) return n;
            
    if(dp[n][m]!=-1) 
        return dp[n][m];
            
            
	// If last characters are same, ignore last char
	// and recur for remaining string
    if( s1[n-1] == s2[m-1] ){		

        if ( dp[n-1][m-1]== -1 ){			
            return dp[n][m] = minDis(s1, s2, n-1, m-1, dp);		
            }	
        else
            return dp[n][m] = dp[n-1][m-1];
    }		
    else{		
        // If characters are not equal, we need to
        // find the minimum cost out of all 3 operations on the first string s1.

        int m1, m2, m3;	 // temp variables
        
        if ( dp[n-1][m]!= -1 ){          // Remove
            m1 = dp[n-1][m];	
        }		
        else{
            m1 = minDis(s1, s2, n-1, m, dp);	
        }		
                
        if( dp[n][m-1]!=-1 ){			 // Insert
            m2 = dp[n][m-1];		
        }		
        else{
            m2 = minDis(s1, s2, n, m-1, dp);	
        }								
        
        if( dp[n-1][m-1]!=-1 ){         // Replace
            m3 = dp[n-1][m-1];	
        }
        else{
            m3 = minDis(s1, s2, n-1, m-1, dp);	
        }	
        
        return dp[n][m] = 1 + min(m1, min(m2, m3));	
    }

}



int main() {
	
    string str1 = "love";
    string str2 = "movie";
        
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
                    
    cout << minDis(str1, str2, n, m, dp);
    return 0;

}

// Ref : https://www.geeksforgeeks.org/edit-distance-dp-5/