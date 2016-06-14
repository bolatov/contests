#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

vector<set<int>> paths;

// https://www.hackerrank.com/contests/w20/challenges/synchronous-shopping
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m >> k;

    int t;
    int64 tk;
    vector<set<int64>> vsi(n, set<int64>());
    for (int i = 0; i < n; ++i) {
        cin >> t;
        while (t--) {
            cin >> tk;
            vsi[0].insert(tk);
        }
    }

    int u, v;
    int64 w;
    vector<vector<pair<int, int64>>> g(n, vector<pair<int, int64>>());
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        v[u].push_back({v, w});
        v[v].push_back({u, w});
    }
    dfs(0, vsi, used);
    int64 ans = INT_MAX;
    // select one or more paths where union of their sets with fish
    // types equals K
    // TODO: Solve
    cout << ans << endl;
    return 0;
}
