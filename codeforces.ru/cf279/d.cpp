#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

#define LL long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    LL n, m, c, h, x, y, mnx, mxx, mny, mxy;
    cin >> n >> m;
    cin >> c;
    std::vector<pair<LL, LL> > hh(c);

    mnx = n;
    mxx = 0;
    mny = m;
    mxy = 0;

    for (int i = 0; i < c; ++i)
    {
        cin >> x >> y;
        hh[i] = make_pair(x,y);
        mnx = min(x, mnx);
        mxx = max(x, mxx);
        mny = min(y, mny);
        mxy = max(y, mxy);
    }

    LL cx = (mxx + mnx) / 2;
    LL cy = (mxy + mny) / 2;

    cin >> h;
    LL dmin, d, r = 1;
    for (int i = 0; i < h; ++i)
    {
        cin >> x >> y;
        d = abs(x-cx)*abs(x-cx) + abs(y-cy)*abs(y-cy);
        if (i == 0) {
            dmin = d;
            mnx = x;
            mny = y;
            r = i + 1;
        } else {
            dmin = min(d, dmin);
            mnx = x;
            mny = y;
            r = i + 1;
        }
    }

    LL res = 0;
    for (int i = 0; i < c; ++i)
    {
        d = abs(mnx - hh[i].first) + abs(mny - hh[i].second);
        res = max(res, d);
    }

    cout << res << endl;
    cout << r << endl;

    return 0;
}
