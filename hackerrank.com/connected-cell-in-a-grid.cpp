#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000;
int m, n;
int cur = 0;
vector<vector<int>> a(N, vector<int>(N, 0));
vector<vector<int>> b(N, vector<int>(N, -1));
vector<vector<bool>> u(N, vector<bool>(N, 0));

void dfs(int i, int j) {
    u[i][j] = 1;
    b[i][j] = cur;
    if (i + 1 < m && a[i + 1][j] && !u[i + 1][j]) {
        dfs(i + 1, j);
    }
    if (j + 1 < n && a[i][j + 1] && !u[i][j + 1]) {
        dfs(i, j + 1);
    }
    if (i + 1 < m && j + 1 < n && a[i + 1][j + 1] && !u[i + 1][j + 1]) {
        dfs(i + 1, j + 1);
    }
    if (i - 1 >= 0 && a[i - 1][j] && !u[i - 1][j]) {
        dfs(i - 1, j);
    }
    if (j - 1 >= 0 && a[i][j - 1] && !u[i][j - 1]) {
        dfs(i, j - 1);
    }
    if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] && !u[i - 1][j - 1]) {
        dfs(i - 1, j - 1);
    }
    if (i - 1 >= 0 && j + 1 < n && a[i - 1][j + 1] && !u[i - 1][j + 1]) {
        dfs(i - 1, j + 1);
    }
    if (i + 1 < m && j - 1 >= 0 && a[i + 1][j - 1] && !u[i + 1][j - 1]) {
        dfs(i + 1, j - 1);
    }
}

void printM(vector<vector<int>> v) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", v[i][j] + 1);
        }
        printf("\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!u[i][j] && a[i][j]) {
                dfs(i, j);
                cur++;

                // printf("%d:%d\n", i + 1, j + 1);
                // printM(b);
                // printf("---------------------\n");
            }
        }
    }

    vector<int> cnt(N, 0);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] > -1) {
                cnt[b[i][j]]++;
                ans = max(ans, cnt[b[i][j]]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}