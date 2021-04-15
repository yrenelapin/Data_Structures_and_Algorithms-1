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

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;


#include <iostream>
using namespace std;
 
const int MAXN = 100010;


/*
Check the Problem Statement here : https://codeforces.com/contest/1480/problem/C
*/
 
int n;
int a[MAXN];
 
int query(int x)
{
	if (1 <= x && x <= n)
	{
		cout << "? " << x << endl;
		cin >> a[x];
	}
}
 
int main()
{
	cin >> n;
	a[0] = a[n + 1] = n + 1;
	int L = 1, R = n;
	int ans;
	while (L <= R)
	{
		int m = (L + R) / 2;
		query(m);
		query(m + 1);
		if (a[m] < a[m + 1])
			{ ans = m;
			R = m - 1; }
		else{
			L = m + 1; }
	}

	cout << "! " << ans << endl;
	return 0;
}