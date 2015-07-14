#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int dist(pair<int, int> &a, pair<int, int> &b) {
    return min(abs(a.first - b.first), abs(a.second - b.second));
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t, n;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        std::vector<pair<int, int> > v(n);
        int x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            v[i] = make_pair(x, y);
        }
        std::vector<bool> u(n, false);
        u[0] = true;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int minDist = 1005;
            int neigh = -1;
            for (int j = 0; j < n; ++j) {
                if (i != j && !u[j] && dist(v[i], v[j]) < minDist) {
                    neigh = j;
                }
            }
            if (neigh > -1) {
                // printf("neigh=%d\n", neigh + 1);
                ans ^= neigh + 1;
                u[neigh] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}