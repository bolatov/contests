#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string str;
    int64 nb, ns, nc, pb, ps, pc, r;
    cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    int64 b = 0, s = 0, c = 0;
    for (char ch : str) {
        if (ch == 'B') {
            b++;
        } else if (ch == 'S') {
            s++;
        } else if (ch == 'C') {
            c++;
        }
    }

    int64 res = 0, lo = 0, hi = 2 * 1e12;
    while (lo <= hi) {
        int64 x = lo + (hi - lo) / 2;
        printf("lo=%lld, x=%lld, hi=%lld\n", lo, x, hi);
        int64 sum = max(0ll, x * b - nb) * pb + max(0ll, x * s - ns) * ps +
                    max(0ll, x * c - nc) * pc;

        if (sum <= r) {
            res = x;
            lo = x + 1;
        } else {
            hi = x - 1;
        }
    }
    cout << res << endl;

    return 0;
}