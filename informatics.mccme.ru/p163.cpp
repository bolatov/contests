#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;
const int n = 8;

queue<pair<int, int>> q;

bool ixy(int i) {
    return 0 <= i && i < n;
}

void f(vector<vector<int>>& v, int x, int y, int tx, int ty) {
    if (ixy(tx) && ixy(ty) && v[x][y] + 1 < v[tx][ty]) {
        v[tx][ty] = v[x][y] + 1;
        q.push({tx, ty});
    }
}

void clearQueue() {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void bfs(vector<vector<int>>& v, int i, int j) {
    v[i][j] = 0;
    q.push({i, j});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        int x = p.first, y = p.second;
        f(v, x, y, x + 1, y - 2);
        f(v, x, y, x + 2, y - 1);
        f(v, x, y, x + 2, y + 1);
        f(v, x, y, x + 1, y + 2);
        f(v, x, y, x - 1, y + 2);
        f(v, x, y, x - 2, y + 1);
        f(v, x, y, x - 2, y - 1);
        f(v, x, y, x - 1, y - 2);
    }
}

bool is(int i, int j) {
    return 0 < i && i < INF && i == j;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s, t;
    cin >> s >> t;

    vector<vector<int>> vi(n, vector<int>(n, INF));
    vector<vector<int>> vj(n, vector<int>(n, INF));

    bfs(vi, s[0] - 'a', s[1] - '1');
    clearQueue();
    bfs(vj, t[0] - 'a', t[1] - '1');

    int mn = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is(vi[i][j], vj[i][j])) {
                mn = min(mn, vi[i][j]);
            }
        }
    }
    cout << ((mn < INF) ? mn : -1) << endl;

    return 0;
}