#include <bits/stdc++.h>

using namespace std;

int res = 0;

void dp(int n, int cnt) {
    if (n <= 1) {
        res++;
        return;
    }
    if ((cnt + 1) % 3) {
        dp(n - 1, cnt + 1);
    }
    dp(n - 1, 0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    dp(n, 1);
    dp(n, 0);
    cout << res << endl;
    return 0;
}