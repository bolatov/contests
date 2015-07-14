#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int itest = 1; itest <= t; itest++) {
        int gp, gc, gf;
        cin >> gp >> gc >> gf;

        int n;
        cin >> n;
        std::vector<int> vgp(n), vgc(n), vgf(n);
        for (int i = 0; i < n; ++i) {
            cin >> vgp[i] >> vgc[i] >> vgf[i];
        }
        bool ok = false;
        for (int i = 1; !(i & (1 << n)); ++i) {
            int sp = 0, sc = 0, sf = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sp += vgp[j];
                    sc += vgc[j];
                    sf += vgf[j];
                }
                if (sp == gp && sc == gc && sf == gf) {
                    ok = true;
                    break;
                }
            }
        }
        printf("Case #%d: %s", itest, (ok ? "yes" : "no"));
        if (itest != t)
            cout << endl;
    }
    return 0;
}