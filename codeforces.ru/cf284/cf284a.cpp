#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, x, l, r;
    cin >> n >> x;
    int ans = 0, cur = 1;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        while (cur + x <= l) {
            cur += x;
        }
        ans += r + 1 - cur;
        cur = r + 1;
    }
    cout << ans << endl;
    return 0;
}