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
        int64 a, b, res;
        cin >> a >> b;
        res = 0;
        for (int j = 31; j >= 0 && (a & 1 << j) == (b & 1 << j); --j) {
            res |= (b & 1 << j);
        }
        printf("%lld\n", res);
    }
    return 0;
}
