#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl


// Minimum number to be added to x to make it divisible by k.
int get(int x, int k) {
    return ( k - (x % k) ) % k;
}

int main() {
    fastIO;
    int n, k, t;
    cin >> t;
    while (t--) {

        int cnt[26] = {0};
        cin >> n >> k;
        string s;
        cin >> s;

        // Noting down the frequencies.
        for (auto c : s) cnt[c - 'a']++;  

        // Calculating the minimal number of characters to be added still inorder to make it beautiful
        int sum = 0, flag = 1;
        for (int i = 0; i < 26; ++i) {
            sum += get(cnt[i], k);
        }

        // If `s` itself is beautiful.
        if (sum == 0) {
            cout << s << '\n';
            flag = 0;
        }

        // Not possible.
        if (n % k != 0) {
            cout << -1 << '\n';
            continue;
        }

        // Iterating to find the end of the common prefix.
        for (int i = n - 1; i >= 0 && flag; --i) {
            

            // Solution given in EDITORIAL.
            sum -= get(cnt[s[i] - 'a'], k);  

            cnt[s[i] - 'a']--;

            sum += get(cnt[s[i] - 'a'], k);
            
            for (int j = s[i] - 'a' + 1; j < 26; ++j) {

                int lst_sum = sum;

                sum -= get(cnt[j], k);
                
                cnt[j]++;
                
                sum += get(cnt[j], k);

                if (i + sum + 1 <= n) {
                
                    for (int pos = 0; pos < i; ++pos) {
                        cout << s[pos];
                    }
                    cout << char('a' + j);

                    string add = "";
                    for (int w = 0; w < 26; ++w) {
                        int f = get(cnt[w], k);
                        while (f) {
                            f--;
                            add += char('a' + w);
                        }
                    }
                    while ((int)add.size() + i + 1 < n) {
                        add += "a";
                    }

                    sort(add.begin(), add.end());
                    cout << add << '\n';
                    flag = 0;
                    break;
                }

                cnt[j]--;
                sum = lst_sum;
            }
        }
    }
    return 0;
}