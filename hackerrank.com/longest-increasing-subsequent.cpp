#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    std::vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    int ans = 0;
    for (int i : dp)
        ans = max(ans, i);
    cout << ans << endl;
    return 0;
}
