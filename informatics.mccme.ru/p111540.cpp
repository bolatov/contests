#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> vg;
vector<bool> u;
vector<int> vt;

void dfs(int i) {
    vt.push_back(i);
    u[i] = 1;
    for (int child : g[i]) {
        if (!u[child]) {
            dfs(child);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m, p, q;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        cin >> p >> q;
        p--;
        q--;
        g[p].push_back(q);
        g[q].push_back(p);
    }

    u.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (u[i]) {
            continue;
        }
        vt.assign(0, 0);
        dfs(i);
        vg.push_back(vt);
    }

    cout << vg.size() << endl;
    for (auto vi : vg) {
        printf("%zu\n", vi.size());
        for (int i : vi) {
            printf("%d ", i + 1);
        }
        printf("\n");
    }
    return 0;
}