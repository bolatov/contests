#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<vector<int>> g;
vector<int> u;
stack<int> st;
bool ok = 1;

void dfs(int src) {
    u[src] = 1;
    for (int child : g[src]) {
        if (u[child] == 0) {
            dfs(child);
        } else if (u[child] == 1) {
            ok = 0;
            return;
        }
    }
    st.push(src);
    u[src] = 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    g.assign(n, vector<int>());
    u.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    for (int i = 0; i < n && ok; ++i) {
        if (u[i] == 0) {
            dfs(i);
        }
    }
    if (ok) {
        puts("Yes");
        while (!st.empty()) {
            printf("%d ", st.top() + 1);
            st.pop();
        }
        printf("\n");
    } else {
        puts("No");
    }

    return 0;
}