#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    n++;
    m++;
    vector<int> rs(n, 0);
    vector<int> rt(n, 0);
    vector<int> cs(m, 0);
    vector<int> ct(m, 0);
    int t, rc, a;
    int i, j;
    for (i = 1; i <= k; i++) {
        cin >> t >> rc >> a;
        if (t == 1) {
            rs[rc] = a;
            rt[rc] = i;
        } else {
            cs[rc] = a;
            ct[rc] = i;
        }
    }

    int v;
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if (rt[i] == ct[j]) {
                v = 0;
            } else if (rt[i] > ct[j]) {
                v = rs[i];
            } else {
                v = cs[j];
            }
            printf("%d ", v);
        }
        printf("\n");
    }
    return 0;
}
