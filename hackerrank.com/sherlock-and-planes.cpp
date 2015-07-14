#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        std::vector<std::vector<int> > m(4, std::vector<int>(3));
        for (int i = 0; i < 4; i++) {
            cin >> m[i][0] >> m[i][1] >> m[i][2];
        }
        bool ok = false;
        for (int col = 0; col < 3; ++col) {
            int an = m[0][col];
            for (int row = 1; row < 4; row++) {
                an &= m[row][col];
            }
            if (!an) {
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
