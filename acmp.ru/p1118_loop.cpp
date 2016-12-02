#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output_loop.txt", "w", stdout);
#endif
    // int t;
    // while (cin >> t) {
    //     if (t < 0) {
    //         return 0;
    //     }
    int n, a, b;
    cin >> n >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n;) {
        cnt++;
        i += a;
        if (i >= n) break;
        i -= b;
    }
    cout << cnt << endl;
    // }
    return 0;
}