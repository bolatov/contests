#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;
int n, x, y, xx, yy;

vector<vector<int>> u;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> ps;
queue<pair<int, int>> q;

bool is(int t) {
    return 0 < t && t < n;
}

void f(int tx, int ty, int txx, int tyy) {
    if (is(txx) && is(tyy) && !u[txx][tyy] && dp[tx][ty] + 1 < dp[txx][tyy]) {
        q.push({txx, tyy});
        dp[txx][tyy] = dp[tx][ty] + 1;
        ps[txx][tyy] = {tx, ty};
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> x >> y >> xx >> yy;
    n++;

    u.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, INF));
    ps.assign(n, vector<pair<int, int>>(n, {-1, -1}));

    dp[x][y] = 0;

    q.push({x, y});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        u[p.first][p.second] = 1;

        int tx = p.first, ty = p.second;
        f(tx, ty, tx + 1, ty - 2);
        f(tx, ty, tx + 2, ty - 1);
        f(tx, ty, tx + 2, ty + 1);
        f(tx, ty, tx + 1, ty + 2);
        f(tx, ty, tx - 1, ty + 2);
        f(tx, ty, tx - 2, ty + 1);
        f(tx, ty, tx - 2, ty - 1);
        f(tx, ty, tx - 1, ty - 2);
    }

    cout << dp[xx][yy] << endl;
    stack<pair<int, int>> st;
    for (auto p = ps[xx][yy]; p.first > -1 && p.second > -1; p = ps[p.first][p.second]) {
        st.push(p);
    }
    while (!st.empty()) {
        printf("%d %d\n", st.top().first, st.top().second);
        st.pop();
    }
    printf("%d %d\n", xx, yy);
    return 0;
}