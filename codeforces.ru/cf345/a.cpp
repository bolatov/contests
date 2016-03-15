#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a, b;
    cin >> a >> b;
    int r = 0;
    while (a && b && (a > 1 || b > 1)) {
        if (a > b) {
            a -= 2;
            b++;
        } else {
            a++;
            b -= 2;
        }
        r++;
    }
    cout << r << endl;
    return 0;
}