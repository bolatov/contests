#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int r = 0;
    for (int i = 0; i < n;) {
        if (i == n - 1) {
            break;
        }
        r++;
        i += (i + 2 < n && v[i] != 1) ? 2 : 1;
    }

    cout << r << endl;
    return 0;
}