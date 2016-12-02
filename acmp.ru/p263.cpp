#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j;
    cin >> n >> i >> j;

    int r = abs(i - j) - 1;
    int l = min(i, j) + n - max(i, j) - 1;
    cout << min(l, r) << endl;
    return 0;
}