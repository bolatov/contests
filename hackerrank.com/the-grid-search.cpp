#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve(std::vector<string> &v, std::vector<string> &p) {
    int n = v.size(), m = p.size();
    for (int i = 0; i + m - 1 < n; ++i) {
        // cout << (i + 1) << endl;
        for (int offset = 0, pos = v[i].find(p[0], offset); pos != string::npos;
             offset++, pos = v[i].find(p[0], offset)) {
            bool ok = 1;
            // cout << "found at row " << (pos + 1) << endl;
            for (int j = 1; j < m; ++j) {
                // cout << "   " << (i + j + 1) << endl;
                if (v[i + j].find(p[j], offset) != pos) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                return true;
        }
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t-- > 0) {
        int r, c;
        cin >> r >> c;
        std::vector<string> v(r);
        for (int i = 0; i < r; ++i) {
            cin >> v[i];
        }
        cin >> r >> c;
        std::vector<string> p(r);
        for (int i = 0; i < r; ++i) {
            cin >> p[i];
        }
        cout << (solve(v, p) ? "YES" : "NO") << endl;
    }
    return 0;
}
