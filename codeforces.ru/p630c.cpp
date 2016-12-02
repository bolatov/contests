#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long n;
    cin >> n;
    cout << (long long)((2 * pow(2, n) - 2)) << endl;
    return 0;
}