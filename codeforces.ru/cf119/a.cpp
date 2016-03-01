#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    vector<int> a(3), dp(10000, -10000);
    cin >> n >> a[0] >> a[1] >> a[2];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1;
        for (int j = 0; j < 3; ++j) {
            if ((i - a[j]) >= 0) {
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}
