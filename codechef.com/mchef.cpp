#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long n, k, m, l, r, c, sum = 0;
        scanf("%lld %lld %lld", &n, &k, &m);
        vector<long long> v(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &v[i]);
            sum += v[i];
        }

        for (int i = 0; i < m; ++i) {
            scanf("%lld %lld %lld", &l, &r, &c);
        }
    }
    return 0;
}