#include <bits/stdc++.h>

using namespace std;

vector<int> memo(1e5, -1);

int dp(vector<int> &v, int i) {
    if (i < 0) {
        return -1;
    }
    if (i <= 1) {
        return v[i];
    }
    int dpv1 = memo[i - 1] < 0 ? dp(v, i - 1) : memo[i - 1];
    int dpv2 = memo[i - 2] < 0 ? dp(v, i - 2) : memo[i - 2];
    memo[i - 1] = dpv1;
    memo[i - 2] = dpv2;
    return v[i] + min(dpv1, dpv2);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << dp(v, n - 1) << endl;

    return 0;
}