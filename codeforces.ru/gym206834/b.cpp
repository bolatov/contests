#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int tMl = k * l / nl;
    int tL = c * d;
    int tS = p / np;
    // printf("tMl=%d, tL=%d, tS=%d\n", tMl, tL, tS);
    cout << min(tMl, min(tL, tS)) / n << endl;

    return 0;
}