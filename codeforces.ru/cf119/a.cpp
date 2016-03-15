#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
<<<<<<< HEAD
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = -1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            int ab = a * i + b * j;
            int k = (n - ab) / c;
            if (ab + k * c == n && k > 0) {
                ans = max(ans, i + j + k);
                // printf("%d %d %d\n", i, j, k);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
