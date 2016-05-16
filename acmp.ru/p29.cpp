#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n), dp(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && dp[i] + (abs(v[i + 1] - v[i])) < dp[i + 1]) {
            dp[i + 1] = dp[i] + abs(v[i + 1] - v[i]);
        }
        if (i + 2 < n && dp[i] + 3 * abs(v[i + 2] - v[i]) < dp[i + 2]) {
            dp[i + 2] = dp[i] + 3 * abs(v[i + 2] - v[i]);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}