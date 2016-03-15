#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, a, b;
    cin >> n;
    map<int, vector<pair<int, int>>> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        if (x.find(a) == x.end()) {
            vector<pair<int, int>> v = {p};
            x[a] = v;
        } else {
            x[a].push_back(p);
        }

        if (y.find(b) == y.end()) {
            vector<pair<int, int>> v = {p};
            y[b] = v;
        } else {
            y[b].push_back(p);
        }
    }

    long long r = 0, dups = 0;
    set<pair<int, int>> s;
    for (auto i = x.begin(); i != x.end(); i++) {
        long long sz = i->second.size();
        r += sz * (sz - 1) / 2;
    }
    for (auto i = y.begin(); i != y.end(); i++) {
        // s.clear();
        long long sz = i->second.size();
        // for (auto p : i->second) {
        //     s.insert(p);
        // }
        // long long dups = sz - s.size();
        r += sz * (sz - 1) / 2;
        // sz -= dups;
    }
    cout << r << endl;

    return 0;
}