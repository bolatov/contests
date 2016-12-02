#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    double n, a, b;
    cin >> n >> a >> b;
    double ans = min(n, 1.0) + ceil(max(n - a, 0.0) / (a - b));
    cout << (int)ans << endl;
    return 0;
}