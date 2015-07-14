#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1234567;

int main() {
    int t, n, ni;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        int ans = 1;
        for (int i = 0; i < n - 1; ++i) {
            cin >> ni;
            ans = (ni * ans) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
