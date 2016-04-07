#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;

    h1 += a * 8;
    if (a <= b && h1 < h2) {
        puts("-1");
    } else if (h1 >= h2) {
        puts("0");
    } else {
        int64 y = 12 * (a - b);
        int64 i = (h2 - h1) / y;
        if (h1 + i * y < h2)
            i++;
        cout << i << endl;
    }

    return 0;
}