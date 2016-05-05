#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> m >> n;
    int sz = 8;
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    dp[n - 1][m - 1] = 1;
    for (int i = 0; i < sz - 1; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (dp[i][j]) {
                if (j - 1 >= 0) {
                    dp[i + 1][j - 1] += dp[i][j];
                }
                if (j + 1 < sz) {
                    dp[i + 1][j + 1] += dp[i][j];
                }
            }
        }
    }
    int sum = 0;
    for (int j = 0; j < sz; ++j) {
        sum += dp[sz - 1][j];
    }
    printf("%d\n", sum);
    return 0;
}