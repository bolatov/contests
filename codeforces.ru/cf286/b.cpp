#include <bits/stdc++.h>
using namespace std;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

typedef pair<int, int> pii;

vector<vector<int> > g;
vector<char> used;
map<pii, set<int> > colors;
void dfs(int v, int color) {
    used[v] = 1;
    for (int child : g[v]) {
        set<int> cols = colors[{ v, child }];
        if (!used[child] && cols.find(color) != cols.end()) {
            dfs(child, color);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        colors[{ a, b }].insert(c);
        colors[{ b, a }].insert(c);
    }
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            used.resize(n, 0);
            for (char &uu : used) {
                uu = 0;
            }
            dfs(s, i);
            ans += used[t];
        }
        printf("%d\n", ans);
    }
    return 0;
}