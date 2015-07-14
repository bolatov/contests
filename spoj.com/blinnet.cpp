#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII>   VPII;
typedef vector<VPII>   VVPII;

struct Edge {
    int from;
    int to;
    int cost;
};

struct EdgeComp {
    bool operator() (const Edge& e1, const Edge& e2) const
    { return e1.cost > e2.cost; }
};

long long solve(VVPII& g) {
    set<int> u;
    long long ans = 0;
    priority_queue<Edge, vector<Edge>, EdgeComp> q;
    VPII::iterator it;
    for (it = g[1].begin(); it != g[1].end(); it++) {
        PII pii = *it;
        Edge e;
        e.from = 1;
        e.to = pii.first;
        e.cost = pii.second;
        q.push(e);
    }
    u.insert(1);
    while (!q.empty()) {
        Edge e = q.top();
        q.pop();
        int to = e.to;
        int cost = e.cost;
        if (u.find(to) != u.end()) continue;
        u.insert(to);
        ans += cost;
        for (it = g[to].begin(); it != g[to].end(); it++) {
            PII pii = *it;
            Edge e;
            e.from = to;
            e.to = pii.first;
            e.cost = pii.second;
            q.push(e);
        }
    }
    return ans;
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
        VVPII g(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> name;
            cin >> p;
            for (int j = 0; j < p; ++j) {
                cin >> neigh >> cost;
                g[i].push_back(make_pair(neigh, cost));
            }
        }
        cout << solve(g) << endl;
    }
    return 0;
}
