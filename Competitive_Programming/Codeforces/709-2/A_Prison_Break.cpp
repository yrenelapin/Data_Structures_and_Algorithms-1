#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " , " << #y << "=" << y << endl

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t,a,b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (a*b) << "\n";
    }

    return 0;
}