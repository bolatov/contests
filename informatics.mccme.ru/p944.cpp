#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e2;
vector<vector<int>> vv(SIZE, vector<int>(SIZE));
int n, m;

int bck(int nn, int mm) {
    if (nn == 0 && mm == 0) {
        return vv[0][0];
    }
    return vv[nn][mm] + min((nn - 1 >= 0 ? bck(nn - 1, mm) : INT_MAX),
                            (mm - 1 >= 0 ? bck(nn, mm - 1) : INT_MAX));
}

int iter() {
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = vv[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + vv[i][0];
    }
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + vv[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + vv[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vv[i][j];
        }
    }
    printf("%d\n", bck(n - 1, m - 1));
    // printf("%d\n", iter());
    // printf("%d\n", abs(iter() - bck(n - 1, m - 1)));
    return 0;
}