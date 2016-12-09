#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    cout << n*(n + 1) / 2 + 1 << endl;

    return 0;
}