#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> dp(1e6 * 4 + 7, INT_MAX);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 3; i <= n; i++) {
        if (dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
        }
        if (dp[i * 2] > dp[i] + 1) {
            dp[i * 2] = dp[i] + 1;
        }
        if (dp[i * 3] > dp[i] + 1) {
            dp[i * 3] = dp[i] + 1;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}