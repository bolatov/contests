#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<pair<int64, int64>> dp(n + 1, {0, 0});
    dp[1] = {1, k - 1};

    for (int i = 2; i <= n; ++i) {
        int64 f = dp[i - 1].second;
        int64 s = (k - 1) * (dp[i - 1].first + dp[i - 1].second);
        dp[i] = {f, s};
    }
    cout << dp[n].second << endl;

    return 0;
}