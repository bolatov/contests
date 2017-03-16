#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    // int all = n * n;
    // int corners = 4 * (all - 4);
    // int sides = 4 * (n - 2) * (all - 6);
    // int other = (n - 2) * (n - 2) * (all - 9);
    // cout << corners + sides + other << endl;
    cout << n* n* n* n - 9 * n* n + 12 * n - 4 << endl;

    return 0;
}