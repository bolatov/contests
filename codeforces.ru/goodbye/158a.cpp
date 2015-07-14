#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k, ans = 0;
    cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        if (v[i] && v[i] >= v[k - 1])
            ans = i + 1;
    }
    cout << ans << endl;

    return 0;
}