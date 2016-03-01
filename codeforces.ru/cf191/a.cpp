#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, ni;
    cin >> n;
    vector<int> v(1e5 + 7, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ni;
        v[ni]++;
    }

    int ans = 1;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i]) {
            int curr = 0;
            if (i > 0 && v[i - 1]) {
                curr += v[i - 1];
            }
            if (i + 1 < (int)v.size() - 1 && v[i + 1]) {
                curr += v[i + 1];
            }
        }
    }

    return 0;
}