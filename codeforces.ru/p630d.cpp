#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n;
    cin >> n;

    cout << 1 + (6 + n * 6) * n / 2 << endl;

    return 0;
}