#include <bits/stdc++.h>

using namespace std;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<pair<int, int> > v(n), edges;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first == 1) {
            q.push(i);
        }
    }

    int u, su;
    while (!q.empty()) {
        u = q.front();
        q.pop();

        if (v[u].first == 0)
            continue;

        su = v[u].second;
        v[su].first -= 1;
        v[su].second ^= u;
        if (v[su].first == 1)
            q.push(su);

        edges.push_back({ u, su });
    }
    cout << edges.size() << endl;
    for (auto e : edges)
        cout << e.first << " " << e.second << endl;
    return 0;
}
