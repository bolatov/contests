#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans;
std::vector<std::vector<int> > g;
std::vector<bool> u;

int dfs(int start) {
    u[start] = true;
    int treeSize = 1;
    for (int i = 0; i < g[start].size(); ++i) {
        int child = g[start][i];
        if (!u[child]) {
            treeSize += dfs(child);
        }
    }
    if (treeSize % 2 == 0) {
        ans++;
        treeSize = 0;
    }
    return treeSize;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    ans = 0;
    cin >> n >> m;
    g.resize(n);
    u.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int ui, vi;
        cin >> ui >> vi;
        ui--;
        vi--;
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    dfs(0);
    cout << ans - 1 << endl;
    return 0;
}
