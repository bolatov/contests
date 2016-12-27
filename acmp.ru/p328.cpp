#include <iostream>
#include <cmath>
using namespace std;

#ifndef int64
#define int64 long long int
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n;
    cin >> n;

    // int64 a1 = 1LL;
    // int64 an = n * 2LL;
    // int64 asum = (a1 + an) * an / 2LL;

    // int64 b1 = 2LL;
    // int64 bm = an - 2LL;
    // int64 m = max(0LL, bm - b1 + 1LL);
    // int64 bsum = (b1 + bm) * m / 2LL;

    // cout << asum + bsum << endl;

    cout << n*(n + 1) * (n + 2) / 2 << endl;

    return 0;
}