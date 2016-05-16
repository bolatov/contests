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
    std::vector<std::vector<int>> vv(n, vector<int>(m)),
        uu(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vv[i][j];
            if (i == 0 || j == 0) {
                uu[i][j] = vv[i][j];
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        uu[i][0] = uu[i - 1][0] + uu[i][0];
    }
    for (int j = 1; j < m; ++j) {
        uu[0][j] = uu[0][j - 1] + uu[0][j];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            uu[i][j] = min(uu[i - 1][j], uu[i][j - 1]) + vv[i][j];
        }
    }
    cout << uu[n - 1][m - 1] << endl;

    return 0;
}