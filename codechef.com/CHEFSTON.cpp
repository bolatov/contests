#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t, n, k;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            int profit = (k / a[i]) * b[i];
            ans = max(profit, ans);
        }
        cout << ans << endl;
    }
    return 0;
}