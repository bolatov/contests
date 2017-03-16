#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct step {
    int r, c, cnt;
    step(int row, int col, int ct = 0) {
        r = row;
        c = col;
        cnt = ct;
    }
};

int N;
const int DIR_LEN = 4;
bool is(int i) {
    return 0 <= i && i < N;
}

int main() {
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    cin >> N;
    vector<vector<bool>> forbidden(N, vector<bool>(N, 0));
    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ch;
            if (ch == 'X') forbidden[i][j] = 1;
        }
    }

    pair<int, int> dirs[] = {
        {-1, 0},  // north
        {0, +1},  // east
        {+1, 0},  // south
        {0, -1},  // west
    };

    int a, b, x, y;
    cin >> a >> b >> x >> y;
    queue<step> q;
    q.push(step(a, b, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, 0));
    int ans = INT_MAX;
    while (!q.empty()) {
        auto st = q.front();
        q.pop();

        visited[st.r][st.c] = 1;

        if (st.r == x && st.c == y) {
            ans = min(st.cnt, ans);
            continue;
        }

        // printf("\n> %d %d (%d)", st.r, st.c, st.cnt);
        for (int i = 0; i < DIR_LEN; i++) {
            int row = st.r + dirs[i].first;
            int col = st.c + dirs[i].second;
            while (is(row) && is(col) && !visited[row][col] && !forbidden[row][col]) {
                // printf("\n      %d %d (%d)", row, col, st.cnt + 1);
                q.push(step(row, col, st.cnt + 1));

                row += dirs[i].first;
                col += dirs[i].second;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
