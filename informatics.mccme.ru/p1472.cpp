#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;

void off(int k) {
    for (int i = 0; i < k; ++i) {
        printf("\t");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<bool>> u(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        int s_row = s.first, s_col = s.second.first, s_cnt = s.second.second;
        u[s_row][s_col] = 1;

        // off(s_cnt);
        // printf("visit [%d %d]\n", s_row + 1, s_col + 1);

        // right
        for (int j = s_col; j < m; ++j) {
            if (g[s_row][j] == 2) {
                cout << s_cnt + 1 << endl;
                return 0;
                // off(s_cnt + 1);
                // printf("![%d %d] mn=%d cnt=%d\n", s_row + 1, j + 1, mn, s_cnt + 1);
                break;
            }

            if (((j + 1 < m && g[s_row][j + 1] == 1) || j + 1 == m)) {
                if (!u[s_row][j]) {
                    // off(s_cnt + 1);
                    // printf("> add [%d %d] cnt=%d\n", s_row + 1, j + 1, s_cnt + 1);
                    q.push({s_row, {j, s_cnt + 1}});
                }
                break;
            }
        }

        // down
        for (int i = s_row; i < n; ++i) {
            if (g[i][s_col] == 2) {
                cout << s_cnt + 1 << endl;
                return 0;
                // off(s_cnt + 1);
                // printf("![%d %d] mn=%d cnt=%d\n", i + 1, s_col + 1, mn, s_cnt + 1);
                break;
            }

            if (((i + 1 < n && g[i + 1][s_col] == 1) || (i + 1 == n))) {
                if (!u[i][s_col]) {
                    // off(s_cnt + 1);
                    // printf("v add [%d %d] cnt=%d\n", i + 1, s_col + 1, s_cnt + 1);
                    q.push({i, {s_col, s_cnt + 1}});
                }
                break;
            }
        }

        // left
        for (int j = s_col; j >= 0; --j) {
            if (g[s_row][j] == 2) {
                cout << s_cnt + 1 << endl;
                return 0;
                // off(s_cnt + 1);
                // printf("![%d %d] mn=%d cnt=%d\n", s_row + 1, j + 1, mn, s_cnt + 1);
                break;
            }

            if (((j - 1 >= 0 && g[s_row][j - 1] == 1) || (j == 0))) {
                if (!u[s_row][j]) {
                    // off(s_cnt + 1);
                    // printf("< add [%d %d] cnt=%d\n", s_row + 1, j + 1, s_cnt + 1);
                    q.push({s_row, {j, s_cnt + 1}});
                }
                break;
            }
        }

        // up
        for (int i = s_row; i >= 0; --i) {
            if (g[i][s_col] == 2) {
                cout << s_cnt + 1 << endl;
                return 0;
                // off(s_cnt + 1);
                // printf("![%d %d] mn=%d cnt=%d\n", i + 1, s_col + 1, mn, s_cnt + 1);
                break;
            }

            if (((i - 1 >= 0 && g[i - 1][s_col] == 1) || (i == 0))) {
                if (!u[i][s_col]) {
                    // off(s_cnt + 1);
                    // printf("^ add [%d %d] cnt=%d\n", i + 1, s_col + 1, s_cnt + 1);
                    q.push({i, {s_col, s_cnt + 1}});
                }
                break;
            }
        }
    }

    return 0;
}