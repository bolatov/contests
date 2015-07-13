#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef int64
#define int64 long long
#endif

bool check(int64 n) {
    int64 nn = n * n;
    vector<int64> v;
    while (nn) {
        v.push_back(nn % 10);
        nn /= 10;
    }
    // printf("nn:");
    // std::vector<int64> vc = v;
    // reverse(vc.begin(), vc.end());
    // for_each(vc.begin(), vc.end(), [](int64 &i) { printf("%lld", i); });
    // printf("\n");
    int len = (int)v.size();
    int rlen = len - (len / 2);
    // printf("rlen=%d\n", rlen);
    int64 r = 0, l = 0, base = 1;
    for (int i = 0; i < rlen; i++) {
        r += v[i] * base;
        base *= 10;
    }
    base = 1;
    for (int i = rlen; i < len; i++) {
        l += v[i] * base;
        base *= 10;
    }
    // printf("nn=%lld, l=%lld, r=%lld\n", n, l, r);
    return l + r == n && r > 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    string no = "INVALID RANGE";
    int64 p, q;
    cin >> p >> q;
    vector<int64> v;
    // printf("p=%lld, q=%lld\n", p, q);
    for (int64 i = p; i <= q; i++) {
        if (check(i)) {
            v.push_back(i);
        }
    }
    if (v.empty()) {
        cout << no << endl;
    } else {
        for_each(v.begin(), v.end(), [](int64 &i) { printf("%lld ", i); });
        printf("\n");
    }

    // int64 test = 4879;
    // printf("%lld => %s\n", test, check(test) ? "yes" : "no");

    return 0;
}
