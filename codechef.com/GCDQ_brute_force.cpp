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
    freopen("answers.txt", "w", stdout);
#endif
    int t, n, q, l, r;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> q;
        int blockSize = sqrt(n);
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        while (q-- > 0) {
            cin >> l >> r;
            l--;
            r--;

            int ans = -1;
            for (int i = 0; i < l; ++i) {
                if (ans == -1)
                    ans = v[i];
                ans = gcd(ans, v[i]);
            }
            for (int i = r + 1; i < n; ++i) {
                if (ans == -1)
                    ans = v[i];
                ans = gcd(ans, v[i]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
