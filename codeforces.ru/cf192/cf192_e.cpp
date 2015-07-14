#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int getDestination(vector<int> &u, vector< set<int> > &g, int source);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N, M;
    cin >> N >> M;
    vector< set<int> > g(N,set<int>());
    int u,v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    if (M == N-1) {
        printf("-1\n");
        return 0;
    }
    vector<int> used(N,2);
    vector< vector<int> > gres(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            int to = getDestination(used, g, i);
            if (to != -1) {
                gres[i].push_back(to);
            }
        }
    }

    for (int i = 0; i < gres.size(); ++i) {
        for (int j : gres[i]) {
            printf("%d %d\n", i+1, j+1);
        }
    }

    return 0;
}

int getDestination(vector<int> &u, vector< set<int> > &g, int source) {
    for (int i = 0; i < u.size(); ++i) {
        if (u[i] > 0 && g[source].find(i) == g[source].end()) {
            u[i]--;
            return i;
        }
    }
    return -1;
}
