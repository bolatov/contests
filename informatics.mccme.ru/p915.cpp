#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int x = v[n];
    for (int i = n - 1; i > 0; i--) {
        x += (v[i] < v[i - 1]) ? v[i] : v[i-- - 1];
    }
    cout << x << endl;
    return 0;
}