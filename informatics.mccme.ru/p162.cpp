#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;
int n, m, di;

queue<pair<int, int>> q;
vector<vector<int>> dp;

bool is(int i, int sz) {
    return 0 <= i && i < sz;
}

void f(pair<int, int> p, int i, int j) {
    if (is(i, n) && is(j, m) && dp[p.first][p.second] + 1 < dp[i][j]) {
        dp[i][j] = dp[p.first][p.second] + 1;
        q.push({i, j});
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    dp.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> di;
            if (di) {
                dp[i][j] = 0;
                q.push({i, j});
            } else {
                dp[i][j] = INF;
            }
        }
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        f(p, i, j + 1);
        f(p, i + 1, j);
        f(p, i, j - 1);
        f(p, i - 1, j);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}