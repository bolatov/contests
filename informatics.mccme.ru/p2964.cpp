#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vv(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vv[i][j];
        }
    }

    vector<vector<int64>> dp(n, vector<int64>(m, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (!vv[i][0]) break;
        dp[i][0] += dp[i - 1][0];
    }
    for (int j = 1; j < m; ++j) {
        if (!vv[0][j]) break;
        dp[0][j] += dp[0][j - 1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (vv[i][j]) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    if (!dp[n - 1][m - 1]) {
        puts("Impossible");
    } else {
        cout << dp[n - 1][m - 1] << endl;
    }

    return 0;
}