#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int hob(int64 num) {
    if (!num) {
        return 0;
    }
    int ret = 0;
    while (num >>= 1LL) {
        ret++;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int q;
    int64 x;
    cin >> q;
    while (q--) {
        cin >> x;
        int h = hob(x);
        int64 ans = 0;
        for (int i = 0; i < h; ++i) {
            if (!(x & 1LL << i)) {
                ans += (1LL << i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}