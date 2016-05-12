#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> dp(20, {0, 0});
    dp[0] = {0, 4}; //
    dp[1] = {2, 5};
    for (int i = 2; i < n; ++i) {
        int f = (1 << i);
        int s = dp[i - 1].second * 2 + dp[i - 1].first;
        dp[i] = {f, s};
        printf("i=%d, f=%d, s=%d, dp[%d]=%d\n", i + 1, f, s, i + 1,
               f * 3 + s * 2);
    }

    cout << dp[n - 1].first * 3 + dp[n - 1].second * 2 << endl;
    return 0;
}