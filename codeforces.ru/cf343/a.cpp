#include <bits/stdc++.h>

using namespace std;

int f(int n) { return n * (n - 1) / 2; }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        int row = 0, col = 0;
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == 'C')
                row++;
            if (v[j][i] == 'C')
                col++;
        }
        r += f(row);
        r += f(col);
    }
    cout << r << endl;

    return 0;
}