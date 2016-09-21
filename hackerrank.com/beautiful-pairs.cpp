#include <bits/stdc++.h>
using namespace std;

const int SZ = 1e3 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, ni;
    cin >> n;
    vector<int> va(SZ, 0), vb(SZ, 0);
    for (int i = 0; i < n; i++) {
        cin >> ni;
        va[ni]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> ni;
        vb[ni]++;
    }
    bool changed = 0;
    for (int i = 0; i < SZ; i++) {
        if (va[i] - vb[i] > 0) {
            vb[i]++;
            changed = 1;
            for (int j = 0; j < SZ; j++) {
                if (va[j] < vb[j]) {
                    vb[j]--;
                    break;
                }
            }
            break;
        }
    }
    for (int i = 0; i < SZ && !changed; i++) {
        if (vb[i]) {
            vb[i]--;
            break;
        }
    }

    int cnt = 0;
    for (int i = 0; i < SZ; i++) {
        if (va[i] && vb[i]) {
            cnt += min(va[i], vb[i]);
        }
    }

    cout << cnt << endl;
    return 0;
}
