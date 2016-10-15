#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
int r, c;
char ch;
int istart, jstart, iend, jend;

vector<pair<int, int>> dirs = {
    {0, 1},   // right  0
    {1, 0},   // down   1
    {0, -1},  // left   2
    {-1, 0},  // up     3
};

char f(int d) {
    switch (d) {
        case 0:
            return '>';
        case 1:
            return 'v';
        case 2:
            return '<';
        default:
            return '^';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> r >> c;
    string s;
    getline(cin, s);
    vector<vector<bool>> g(r, vector<bool>(c, 0));
    for (int i = 0; i < r; ++i) {
        getline(cin, s);
        for (int j = 0; j < c; ++j) {
            ch = s[j];
            if (ch == 'X') {
                g[i][j] = 1;
            } else if (ch == 'S') {
                istart = i;
                jstart = j;
            } else if (ch == 'F') {
                iend = i;
                jend = j;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < (int)dirs.size(); i++) {
        if (!g[istart + dirs[i].first][jstart + dirs[i].second]) {
            q.push(istart + dirs[i].first);
            q.push(jstart + dirs[i].second);
            q.push(i);
            q.push(1);
        }
    }

    while (!q.empty()) {
        // int i = p.first, j = p.second.first, d = p.second.second;
        int i = q.front();
        q.pop();

        int j = q.front();
        q.pop();

        int d = q.front();
        q.pop();

        int cnt = q.front();
        q.pop();

        // printf("visit [%d, %d] %d\n", i + 1, j + 1, cnt);

        if (i == iend && j == jend) {
            cout << cnt << endl;
            break;
        }

        for (int di = 0; di < 2; ++di) {
            d = (d + di) % (int)dirs.size();
            int is = i + dirs[d].first, js = j + dirs[d].second;
            if (!g[is][js]) {
                // printf("\t%c add [%d %d]\n", f(d), is + 1, js + 1);
                q.push(is);
                q.push(js);
                q.push(d);
                q.push(cnt + 1);
            }
        }
    }

    return 0;
}