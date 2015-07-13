#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        std::vector<string> v(6);
        for (size_t i = 0; i < v.size(); ++i) {
            cin >> v[i];
        }
        // front, back, left, right, top and bottom
        bool ok =
            // front & left & (top | bottom)
            (v[0] == v[2] && (v[0] == v[4] || v[0] == v[5])) ||

            // front & right & (top | bottom)
            (v[0] == v[3] && (v[0] == v[4] || v[0] == v[5])) ||

            // back & left & (top | bottom)
            (v[1] == v[2] && (v[1] == v[4] || v[1] == v[5])) ||

            // back & right & (top | bottom)
            (v[1] == v[3] && (v[1] == v[4] || v[1] == v[5]));

        puts(ok ? "YES" : "NO");
    }
    return 0;
}