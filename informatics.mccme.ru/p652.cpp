#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<bool>> u;
int n, m;

void dfs(int i, int j) {
    u[i][j] = 1;

    // down
    if (i + 1 < m && g[i + 1][j] && !u[i + 1][j]) {
        dfs(i + 1, j);
    }
    // right
    if (j + 1 < n && g[i][j + 1] && !u[i][j + 1]) {
        dfs(i, j + 1);
    }

    // up
    if (i - 1 >= 0 && g[i - 1][j] && !u[i - 1][j]) {
        dfs(i - 1, j);
    }

    // left
    if (j - 1 >= 0 && g[i][j - 1] && !u[i][j - 1]) {
        dfs(i, j - 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> m >> n;
    g.assign(m, vector<int>(n, 0));
    u.assign(m, vector<bool>(n, 0));

    char ch;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ch;
            if (ch == '#') {
                g[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!u[i][j] && g[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}