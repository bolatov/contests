#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int x, y;
    cin >> x >> y;

    if (x == 1 && y == 1) {
        puts("0");
    } else if (x != y) {
        puts("1");
    } else {
        puts("2");
    }

    return 0;
}