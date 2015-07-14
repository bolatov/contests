#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    freopen("input.txt", "r", stdin);
    int t, m, n;
    cin >> t;
    while (t-- > 0) {
        cin >> m >> n;
        m--;
        n--;
        vector<ll> vm(m), vn(n);
        for (int i = 0; i < m; ++i) {
            cin >> vm[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> vn[i];
        }
        ll ans = 0;
        sort(vm.begin(), vm.end(), greater<ll>());
        sort(vn.begin(), vn.end(), greater<ll>());
        ll cols = 1, rows = 1;
        for (int i = 0, j = 0; i < m || j < n;) {
            ll dy = 0, dx = 0;
            if (i >= m)
                dx = vn[j++];
            else if (j >= n)
                dy = vm[i++];
            else {
                if (vm[i] == vn[j]) {
                    if (rows <= cols)
                        dy = vm[i++];
                    else
                        dx = vn[j++];
                } else if (vm[i] > vn[j])
                    dy = vm[i++];
                else
                    dx = vn[j++];
            }
            ans += (dy * rows % mod) + (dx * cols % mod);
            ans %= mod;

            cols += (dy > 0);
            rows += (dx > 0);

            // cout << "dy:   " << dy << ", dx:   " << dx << endl;
            // cout << "rows: " << rows << ", cols: " << cols << endl;
            // cout << "ans: " << ans << endl << endl;
        }
        cout << ans << endl;
    }
    return 0;
}