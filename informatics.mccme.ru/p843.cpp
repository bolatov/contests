#include <bits/stdc++.h>

using namespace std;

//
// backtracking - top down
//
int bck(int n) {
    if (n <= 1) {
        return 1;
    }
    int n_2 = bck(n / 2);
    int n_2_1 = bck(n / 2 - 1);
    return (n % 2) ? n_2 - n_2_1 : n_2 + n_2_1;
}

//
// iterative - bottom up
//
int iter(int n) {
    vector<int> dp(1e5, 1);
    for (int i = 1; i <= n; i++) {
        dp[2 * i] = dp[i] + dp[i - 1];
        dp[2 * i + 1] = dp[i] - dp[i - 1];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    // cout << bck(n) << endl;
    cout << iter(n) << endl;

    return 0;
}