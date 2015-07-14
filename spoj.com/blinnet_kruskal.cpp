#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dsu_get(vector<int>& p, int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get(p, p[v]));
}

void dsu_unite(vector<int>& p, int a, int b) {
    a = dsu_get(p, a);
    b = dsu_get(p, b);
    if (rand() & 1)
        swap(a, b);
    if (a != b)
        p[a] = b;
}

int solve(vector< pair <int, pair<int,int> > >& g, int n) {
    // n - vertices
    // m - edges
    int cost = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int m = g.size();
    sort(g.begin(), g.end());
    for (int i = 0; i < m; i++) {
        int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if (dsu_get(p, a) != dsu_get(p, b)) {
            cost += l;
            dsu_unite(p, a, b);
        }
    }

    return cost;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t,n,p,neigh,cost;
    cin >> t;
    string name;
    while (t--) {
        cin >> n;
        vector< pair <int, pair<int,int> > > g; // cost - from - to
        for (int i = 0; i < n; ++i) {
            cin >> name;
            cin >> p;
            for (int j = 0; j < p; ++j) {
                cin >> neigh >> cost;
                g.push_back(make_pair(cost, make_pair(i, neigh-1)));
            }
        }
        cout << solve(g, n) << endl;
    }
    return 0;
}
