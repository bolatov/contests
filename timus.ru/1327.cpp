#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a, b;
    cin >> a >> b;
    int days = b - a + 1;
    cout << (days / 2) + (days % 2) - max(0, min(1 - (a % 2), 1 - (b % 2))) << endl;

    return 0;
}