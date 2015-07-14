#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, si;
    cin >> n;
    vector<int> v(5, 0);
    for (int i = 0; i < n; ++i) {
        cin >> si;
        v[si]++;
    }
    int ans = v[4];

    if (v[3] && v[1]) {
        int vmin = min(v[3], v[1]);
        ans += vmin;
        v[3] -= vmin;
        v[1] -= vmin;
    }
    ans += v[3];

    ans += v[2] / 2;
    v[2] %= 2;
    if (v[2] && v[1]) {
        ans++;
        v[2]--;
        v[1] -= (v[1] >= 2) ? 2 : 1;
    }
    ans += v[2];

    ans += v[1] / 4;
    ans += (v[1] % 4 > 0);

    cout << ans << endl;
    return 0;
}