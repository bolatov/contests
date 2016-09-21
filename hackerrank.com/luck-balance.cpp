#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, l, b;
    cin >> n >> k;
    vector<pair<int, int>> v;
    while (n--) {
        cin >> l >> b;
        v.push_back({l, b});
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (const auto p : v) {
        ans += (p.second == 0) ? p.first : (k-- > 0) ? p.first : -1 * p.first;
    }
    cout << ans << endl;
    return 0;
}
