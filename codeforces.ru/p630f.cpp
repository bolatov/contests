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

    int64 c5 = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5;
    int64 c6 = c5 * (n - 5) / 6;
    int64 c7 = c6 * (n - 6) / 7;
    cout << c5 + c6 + c7 << endl;

    return 0;
}