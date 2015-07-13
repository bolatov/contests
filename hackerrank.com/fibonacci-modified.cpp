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
    int64 a, b, n, t;
    cin >> a >> b >> n;
    for (int i = 3; i <= n; ++i) {
        t = b;
        b = b * b + a;
        a = t;
        printf("%d = %lld\n", i, b);
    }
    printf("%lld\n", b);
    return 0;
}
