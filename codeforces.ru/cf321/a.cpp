#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] >= v[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            ans = max(ans, dp[i]);
        }
    }

    cout << ans << endl;

    return 0;
}