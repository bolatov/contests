#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

void build(vector<int64> &v, vector<int64> &t, int lvl, int l, int r) {
    if (l == r) {
        t[lvl] = v[l];
    } else {
        int mid = (l + r) / 2;
        build(v, t, lvl * 2, l, mid);
        build(v, t, lvl * 2 + 1, mid + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int64 solve(vector<int64> &t) {}

int main() {
    int n;
    cin >> n;
    vector<int64> v(n), t(n * 4, -1);
    build(v, t, 1, 0, n - 1);
    cout << solve(t) << endl;
    return 0;
}
