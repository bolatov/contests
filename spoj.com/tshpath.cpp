#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <set>
#include <climits>

using namespace std;

#define ll long long

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int solve(int s, int t, vvpii& g) {
    int n = g.size();
    vi dist(n, INT_MAX);
    dist[s] = 0;
    set<pii> q;
    set<int> u;
    q.insert(make_pair(0,s));    // cost, vertex
    while (!q.empty()) {
        pii top = *q.begin();
        q.erase(q.begin());

        int from = top.second;

        if (u.find(from) != u.end()) continue;
        u.insert(from);

        for(vpii::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
            int cost = it->second;
            int to = it->first;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                q.insert(pii(dist[to], to));
            }
        }
    }
    return dist[t];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int s;
    cin >> s;
    for (int itest = 0; itest < s; ++itest) {
        int n;
        cin >> n;
        map<string, int> m;
        vvpii g(n+1);
        for (int icity = 1; icity <= n; ++icity) {
            string city;
            cin >> city;
            m[city] = icity;
            int p;
            cin >> p;
            int nr, cost;
            for (int ineighbour = 0; ineighbour < p; ++ineighbour) {
                cin >> nr >> cost;
                g[icity].push_back(make_pair(nr, cost));
            }
        }
        int r;
        cin >> r;
        string source, dest;
        for (int iquery = 0; iquery < r; ++iquery) {
            cin >> source >> dest;
            int src = m[source];
            int trg = m[dest];
            cout << solve(src, trg, g) << endl;
        }
    }
    return 0;
}
