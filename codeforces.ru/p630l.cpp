#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    // Phase 1
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    n = v[0];
    n *= 10;

    n += v[2];
    n *= 10;

    n += v[4];
    n *= 10;

    n += v[3];
    n *= 10;

    n += v[1];

    // printf("%d\n", n);

    int64 md7 = 1e7;
    int64 md5 = 1e5;
    int64 m = n;
    for (int i = 1; i < 5; ++i) {
        m *= n;
        m %= md7;
    }

    printf("%05lld\n", m % md5);

    return 0;
}