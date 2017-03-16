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

    int64 c = n * (n - 1LL) / 2LL * (n - 2LL) / 3LL * (n - 3LL) / 4LL * (n - 4LL) / 5LL;
    cout << c* c * 120LL << endl;
    return 0;
}