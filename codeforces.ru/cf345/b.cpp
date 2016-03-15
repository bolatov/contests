#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, a;
    cin >> n;
    vector<int> v(1001, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v[a]++;
    }
    int r = 0;
    while (true) {
        bool any = 0;
        bool prev = 0;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i]) {
                // printf("i=%d, v[%d]=%d\n", i, v[i]);
                any = 1;
                v[i]--;
                if (prev) {
                    r++;
                }
                prev = 1;
            }
        }
        if (!any) {
            break;
        }
    }
    cout << r << endl;

    return 0;
}