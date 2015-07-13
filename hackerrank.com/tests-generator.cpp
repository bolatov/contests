#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
    freopen("input.txt", "w", stdout);
    int t = 200;
    printf("%d\n", t);
    int MAX = 1 << 31;
    while (t--) {
        int a = rand() % MAX + 1;
        int b = rand() % MAX + 1;
        int mn = min(a, b);
        int mx = max(a, b);
        printf("%d %d\n", mn, mx);
    }
    return 0;
}
