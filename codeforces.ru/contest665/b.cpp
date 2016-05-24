#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m, k, aij;
    cin >> n >> m >> k;
    vector<int> vp(k);
    for (int i = 0; i < k; ++i) {
        cin >> vp[i];
    }

    int r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> aij;
            int pos = 0;
            for (int ip = 0; ip < (int)vp.size(); ++ip) {
                if (vp[ip] == aij) {
                    pos = ip;
                    r += pos + 1;
                    break;
                }
            }
            vp.insert(vp.begin(), vp[pos]);
            vp.erase(vp.begin() + pos + 1);

            // printf("r=%d\n", r);
            // for (int vpi : vp) {
            //     printf("%d ", vpi);
            // }
            // printf("\n======================================\n");
        }
    }
    printf("%d\n", r);

    return 0;
}