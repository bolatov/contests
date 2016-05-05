#include <bits/stdc++.h>

using namespace std;

int bck(int n, int m) {
    if (n <= 1 && m <= 1) {
        return 1;
    }
    return (n - 1 > 0 ? bck(n - 1, m) : 0) + (m - 1 > 0 ? bck(n, m - 1) : 0);
}

int iter(int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 1));
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    printf("%d\n", bck(n, m));
    // printf("%d\n", iter(n, m));
    return 0;
}