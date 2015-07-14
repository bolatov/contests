#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    int t, n, q, l, r;
    // cin >> t;
    scanf("%d", &t);
    while (t-- > 0) {
        // cin >> n >> q;
        scanf("%d %d", &n, &q);
        int blockSize = sqrt(n);
        std::vector<int> v(n), m;
        for (int i = 0; i < n; ++i) {
            // cin >> v[i];
            scanf("%d", &v[i]);
            if (i % blockSize == 0) {
                m.push_back(v[i]);
            } else {
                int last = m.size() - 1;
                m[last] = gcd(v[i], m[last]);
            }
        }

        while (q-- > 0) {
            // cin >> l >> r;
            scanf("%d %d", &l, &r);
            l--;
            r--;
            int ans = -1;
            for (int j = 0; j < l;) {
                if (ans < 0)
                    ans = v[j];

                if (j % blockSize == 0 && (j + blockSize - 1) < l) {
                    ans = gcd(ans, m[j / blockSize]);
                    j += blockSize;
                } else {
                    ans = gcd(ans, v[j]);
                    j++;
                }
            }
            for (int j = r + 1; j < n;) {
                if (ans < 0)
                    ans = v[j];

                if (j % blockSize == 0 && (j + blockSize - 1) < n) {
                    ans = gcd(ans, m[j / blockSize]);
                    j += blockSize;
                } else {
                    ans = gcd(ans, v[j]);
                    j++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
