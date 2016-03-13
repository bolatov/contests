#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    vector<pair<int, int>> m, f;
    char c;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> c >> a >> b;
        if (c == 'F') {
            f.push_back(make_pair(a, b));
        } else {
            m.push_back(make_pair(a, b));
        }
    }

    int r = 0;
    for (int i = 1; i <= 366; ++i) {
        int fc = 0;
        for (auto p : f) {
            fc += p.first <= i && i <= p.second;
        }
        int mc = 0;
        for (auto p : m) {
            mc += p.first <= i && i <= p.second;
        }
        r = max(r, 2 * min(fc, mc));
    }
    cout << r << endl;

    return 0;
}