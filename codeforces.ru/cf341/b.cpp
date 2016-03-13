#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n = 1000;
    int64 sz = 4 * n - 6;
    vector<int64> v1(sz, 0), v2(n + n, 0);
    int m;
    cin >> m;
    int64 x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        if (x <= y) {
            v1[y - x]++;
        } else {
            v1[x - y + n]++;
        }
        v2[x + y]++;
    }
    int64 r = 0;
    for (int64 i : v1) {
        r += i * (i - 1) / 2;
    }
    for (int64 i : v2) {
        r += i * (i - 1) / 2;
    }
    cout << r << endl;
    return 0;
}
