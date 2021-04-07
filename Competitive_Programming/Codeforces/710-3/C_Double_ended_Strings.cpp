    #include <bits/stdc++.h>
    using namespace std;
    #define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    #define all(x) (x).begin(), (x).end()
    #define deb(x) cout << #x << " = " << x << endl
    #define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
    typedef long long ll;
    const int mod = 1e9 + 7;


    void solve() {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        // `ans` is the length of the strings when the both input strings a & b become equal for 
        //  minimum number of operations. In other words, `ans` is the maximum length of the common substring between a & b.

        int ans = 0;
        for (int len = 1; len <= min(n, m); len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= m; j++) {
                    // cout << a.substr(i, len) << " " << b.substr(j, len) << endl;
                    if (a.substr(i, len) == b.substr(j, len)) {
                        ans = max(ans, len);
                    }
                }
            }
        }
        cout << a.size() + b.size() - 2 * ans << "\n";
    }

    int main() {
        fastIO;
        int t = 1;
        cin >> t; // Comment if only 1 testcase.
        while(t--) {
        solve();
        }

        return 0;
    }