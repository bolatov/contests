#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int GCD(int a, int b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

int count(int n, int gcd) {
    if (n == gcd)
        return 0;
    int a = -1, b = -1, c = -1;
    if (n % 2 == 0) {
        int r = count(n / 2, gcd);
        a = (r >= 0) ? r + 1 : -1;
    }
    if (n % 3 == 0) {
        int r = count(2 * n / 3, gcd);
        b = (r >= 0) ? r + 1 : -1;
    }
    if (n % 5 == 0) {
        int r = count(4 * n / 5, gcd);
        c = (r >= 0) ? r + 1 : -1;
    }
    a = (a < 0) ? MAX_INT : a;
    return min();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a, b;
    cin >> a >> b;

    if (a == b) {
        puts("0");
        return 0;
    }
    int gcd = GCD(a, b);
    int acnt = count(a, gcd);
    int bcnt = count(b, gcd);
    if (acnt < 0 || bcnt < 0) {
        puts("-1");
    } else {
        cout << (acnt + bcnt) << endl;
    }

    return 0;
}