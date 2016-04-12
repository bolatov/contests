#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif
int GCD(int a, int b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
int LCM(int a, int b) { return a * (b / GCD(a, b)); }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    int lcm = -1;
    vector<int> m(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        lcm = (i == 0) ? m[i] : LCM(lcm, m[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    // for (int i = 0; i < n; ++i) {
    //     printf("%d m=%d r=%d\n", i + 1, m[i], r[i]);
    // }

    set<int> s;
    for (int d = 1; d <= lcm; ++d) {
        for (int j = 0; j < n; ++j) {
            if (d % m[j] == r[j]) {
                // printf("%d mod %d == %d\n", d, m[j], r[j]);
                s.insert(d);
            }
        }
    }
    int cnt = (int)s.size();
    // printf("%d, %d\n", cnt, lcm);
    double ret = cnt / (double)lcm;
    printf("%.6f\n", ret);

    return 0;
}