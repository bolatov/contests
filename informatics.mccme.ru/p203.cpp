#include <bits/stdc++.h>

using namespace std;

//
// backtracking - top down
//
int bck(int n) {
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n; i >= 0; i--) {
        if (i - 3 >= 0)
            dp[i - 3] += dp[i];
        if (i - 2 >= 0)
            dp[i - 2] += dp[i];
        if (i - 1 >= 0)
            dp[i - 1] += dp[i];
    }
    return dp[0];
}

//
// iterative - bottom up
//
int iter(int n) {
    vector<int> dp(1e5, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
        dp[i + 3] += dp[i];
    }
    return dp[n];
}

int main() {
    int n = 5;
    cin >> n;
    // cout << bck(n) << endl;
    cout << iter(n) << endl;

    return 0;
}