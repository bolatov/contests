#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp = {0, 2, 3};
    for (int i = 3; i <= n; i++) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    cout << dp[n] << endl;
    return 0;
}