#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t-- > 0) {
        int s;
        string p, q;
        cin >> s >> p >> q;
        int n = p.size();
        int ans = 0;
        for (int k = n; k >= 0; --k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    int mm = 0;
                    for (int x = 0; x < k; ++x) {
                        mm += (p[i + x] != q[j + x]);
                    }
                    if (mm <= s)
                        ans = max(ans, k);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
