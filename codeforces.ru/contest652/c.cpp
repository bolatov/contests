#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int64 f(int i, int j) {
    int64 n = (int64)(abs(i - j) + 1);
    return n * (n - 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m, vi;
    cin >> n;
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> vi;
        u[vi - 1] = i;
    }
    int a, b, s, t;
    vector<int> v(n, -1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        s = min(u[a - 1], u[b - 1]);
        t = max(u[a - 1], u[b - 1]);

        v[s] = max(v[s], t);
    }

    int64 ret = (int64)n;
    int i = 0, k = n;
    for (j = 0; j < n; ++j) {
        if (u[j]) {
            u[] k = min(k, u[j]);
        }
        if (j == k) {
            ret += f(i, j - 1);
            i = k;
        }
    }

    return 0;
}