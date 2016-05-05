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
    queue<pair<int, int>> q;
    q.push({1, 1});
    int64 r = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        if (i == n && j == m) {
            r++;
            continue;
        }

        if (i + 2 <= n && j + 1 <= m) {
            q.push({i + 2, j + 1});
        }
        if (i + 1 <= n && j + 2 <= m) {
            q.push({i + 1, j + 2});
        }
        if (i + 2 <= n && j - 1 >= 1) {
            q.push({i + 2, j - 1});
        }
        if (i - 1 >= 1 && j + 2 <= m) {
            q.push({i - 1, j + 2});
        }
    }
    cout << r << endl;

    return 0;
}