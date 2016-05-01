#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dp = {{0, 0}, {1, 2}};
    for (int i = 2; i <= n; i++) {
        int a = dp[i - 1].second;
        int x = dp[i - 1].first * 2 + dp[i - 1].second * 2;
        dp.push_back({a, x});
    }
    cout << (dp[n].first + dp[n].second) << endl;
    return 0;
}