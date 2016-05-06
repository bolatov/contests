#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

vector<vector<int>> g = {
    {4, 6},    // 0
    {6, 8},    // 1
    {7, 9},    // 2
    {4, 8},    // 3
    {0, 3, 9}, // 4
    {},        // 5
    {0, 1, 7}, // 6
    {2, 6},    // 7
    {1, 3},    // 8
    {2, 4},    // 9
};

//
// Solved by reading the tutorial
//
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    vector<vector<int64>> dp(10, vector<int64>(n + 1, 0));
    for (int i = 0; i < (int)dp.size(); i++) {
        dp[i][1] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < 10; ++i) {
            for (int k : g[i]) {
                dp[k][len] += dp[i][len - 1];
            }
        }
    }
    int64 sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += dp[i][n];
    }
    sum -= dp[0][n];
    sum -= dp[8][n];
    cout << sum << endl;

    return 0;
}