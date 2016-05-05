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
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 2 < n && j + 1 < m) {
                dp[i + 2][j + 1] += dp[i][j];
            }
            if (i + 1 < n && j + 2 < m) {
                dp[i + 1][j + 2] += dp[i][j];
            }
        }
    }
    printf("%d\n", dp[n - 1][m - 1]);

    return 0;
}