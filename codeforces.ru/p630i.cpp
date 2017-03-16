#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 k;
    cin >> k;

    int64 q = (1LL << (2 * k - 6));
    cout << 24LL * q + 9 * (k - 3) * q << endl;

    return 0;
}