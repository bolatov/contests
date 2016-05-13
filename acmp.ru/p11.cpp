#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

void f(vector<int> v) {
    printf("f: ");
    for (int i : v) {
        printf("%d", i);
    }
    printf("\n");
}

vector<int> add(vector<int> &v, vector<int> &u) {
    int n = (int)v.size(), m = (int)u.size();
    int q = 0;
    vector<int> w;
    int sum = 0;
    for (int i = 0; i < max(n, m); ++i) {
        if (i < n && i < m) {
            sum = v[i] + u[i];
        } else if (i < n) {
            sum = v[i];
        } else {
            sum = u[i];
        }
        sum += q;
        w.push_back(sum % 10);
        q = sum / 10;
    }
    if (q) {
        w.push_back(q);
    }
    return w;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> k >> n;

    vector<vector<int>> dp(n + 1, vector<int>(1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j <= n) {
                dp[i + j] = add(dp[i], dp[i + j]);
            }
        }
    }
    for (int i = dp[n].size() - 1; i >= 0; --i) {
        printf("%d", dp[n][i]);
    }

    printf("\n");
    return 0;
}