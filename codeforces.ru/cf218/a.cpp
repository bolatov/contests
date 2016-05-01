#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int r = 0;
    for (int i = 0; i < k; ++i) {
        int c = 0, d = 0;
        for (int j = 0; j < n / k; ++j) {
            c += v[j * k + i] == 1;
            d += v[j * k + i] != 1;
        }
        r += min(c, d);
    }
    printf("%d\n", r);

    return 0;
}