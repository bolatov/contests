#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n, m;
    cin >> n >> m;

    int64 row = n * (n + 1) / 2;
    int64 col = m * (m + 1) / 2;
    cout << row* col << endl;

    return 0;
}