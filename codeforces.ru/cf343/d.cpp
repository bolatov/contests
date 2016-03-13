#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238;

double vol(double r, double h) { return h * PI * r * r; }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif



    int n;
    cin >> n;
    double r, h;
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> r >> h;
        v[i] = vol(r, h);
    }

    vector<int> dp(n, 0), prev(n, -1);
    int bestEnd = 0;
    int maxLen = 1;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            bestEnd = i;
            maxLen = dp[i];
        }
    }

    double ret = 0;
    // for (int i = bestEnd; i >= 0; i = prev[i]) {
    //     ret += v[i];
    // }
    printf("%.10f\n", ret);


    return 0;
}
