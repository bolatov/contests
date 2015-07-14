#include <cmath>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

bool solve(int r, int k) {
    int rsqr = sqrt(r);
    set<pair<int, int> > points;
    points.insert(make_pair(0, rsqr));
    points.insert(make_pair(0, -1 * rsqr));
    points.insert(make_pair(rsqr, 0));
    points.insert(make_pair(-1 * 0, 0));
    for (int i = 1; i <= rsqr; ++i) {
        int lo = i, hi = rsqr;
        while (lo < hi) {
            int j = lo + (hi - lo) / 2;
            int mul = i * i + j * j;
            if (mul == r) {
                points.insert(make_pair(i, j));
                points.insert(make_pair(-1 * i, j));
                points.insert(make_pair(-1 * i, -1 * j));
                points.insert(make_pair(i, -1 * j));

                points.insert(make_pair(j, i));
                points.insert(make_pair(-1 * j, i));
                points.insert(make_pair(-1 * j, -1 * i));
                points.insert(make_pair(j, -1 * i));
                break;
            } else if (mul < r) {
                lo = j + 1;
            } else {
                hi = j - 1;
            }
        }
    }
    return k >= points.size();
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t-- > 0) {
        int r, k;
        cin >> r >> k;
        if (solve(r, k))
            puts("possible");
        else
            puts("impossible");
    }
    return 0;
}