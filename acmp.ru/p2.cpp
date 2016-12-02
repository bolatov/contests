#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    cout << (1 + n) * (abs(n - 1) + 1) / 2 << endl;
    return 0;
}