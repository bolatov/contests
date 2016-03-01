#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int sz = 5;
    vector<int> m(sz, 0);
    for (int i = 0; i < sz; ++i) {
        cin >> m[i];
    }
    vector<int> w(sz, 0);
    for (int i = 0; i < sz; ++i) {
        cin >> w[i];
    }
    int hs, hu;
    cin >> hs >> hu;
    double r = 0;
    vector<int> x = {500, 1000, 1500, 2000, 2500};
    for (int i = 0; i < sz; ++i) {
        double d1 = 0.3 * x[i];
        double d2 = x[i] - m[i] * x[i] / 250 - 50 * w[i];

        if (d1 > d2)
            r += d1;
        else
            r += d2;
    }
    r += hs * 100;
    r -= hu * 50;
    cout << r << endl;

    return 0;
}
