#include <bits/stdc++.h>

using namespace std;

int main() {
    // vector<int> v = {1000, 10, 100, 1200, 20, 90};
    // vector<int> v = {5000, 15, 23, 4000, 17, 22};
    vector<int> v(6);
    for (int i = 0; i < 6; ++i) {
        cin >> v[i];
    }

    int before = v[0] * v[2] + v[3] * v[5];
    int iLeft = v[0] - v[0] * v[1] / 100;
    int jLeft = v[3] - v[3] * v[4] / 100;
    int pairs = min(iLeft, jLeft);
    int after = pairs * (v[2] + v[5]);
    cout << before - after << endl;

    return 0;
}