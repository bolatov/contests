#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef int64
#define int64 long long
#endif
int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int64 b, w, x, y, z;
        cin >> b >> w;
        cin >> x >> y >> z;
        int64 bc = min(x, y + z);
        int64 wc = min(y, x + z);
        cout << b *bc + w *wc << endl;
    }
    return 0;
}