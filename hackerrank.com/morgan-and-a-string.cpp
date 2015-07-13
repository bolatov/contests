#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = (int)a.size();
        int m = (int)b.size();
        string res = "";
        for (int i = 0, j = 0; i < n || j < m;) {
            if (i == n) {
                res.append(b.begin() + j, b.end());
                break;
            } else if (j == m) {
                res.append(a.begin() + i, a.end());
                break;
            } else if (a[i] == b[j]) {
                if (i + 1 < n && j + 1 < m && a[i + 1] < b[j + 1]) {
                    res.append(1, a[i++]);
                } else {
                    res.append(1, b[j++]);
                }
            } else if (a[i] < b[j]) {
                res.append(1, a[i++]);
            } else {
                res.append(1, b[j++]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
