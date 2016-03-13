#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int r = v[n - 1] - v[0];
    for (int i = n - 1; i < m; ++i) {
        r = min(r, v[i] - v[i - n + 1]);
    }
    cout << r << endl;
    return 0;
}