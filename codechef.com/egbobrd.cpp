#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long n, k, ck = 0, ai, res = 0;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> ai;
            if (ck < ai) {
                ai -= ck;
                ck = 0;
                long long p = 1;
                if (ai > k) {
                    p = (ai / k) + (ai % k != 0);
                }
                res += p;
                ck = p * k;
            }
            ck -= ai;
            ck -= (ck) ? 1 : 0;
        }
        printf("%lld\n", res);
    }
    return 0;
}