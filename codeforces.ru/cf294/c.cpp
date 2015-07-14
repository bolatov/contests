#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n, m;
    cin >> n >> m;
    int64 ans = 0;
    if (n == 0 || m == 0 || n + m < 3) {
        puts("0");
        return 0;
    }

    while (n >= 2 || m >= 2) {
        if (n > m) {
            ans++;
            n -= 2;
            m--;
        } else {
            ans++;
            m -= 2;
            n--;
        }
        if (n == 0 || m == 0)
            break;
    }
    cout << ans << endl;

    return 0;
}