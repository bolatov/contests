#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 a,b,n;
    cin >> a >> b >> n;
    for (int64 i = 0; i < n; ++i)
    {
        int64 l,t,m;
        cin >> l >> t >> m;

        int64 sl = a + l*b;
        int64 lo = l, hi = 1e6+7;
        int64 res = -1;
        while (lo <= hi) {
            int64 mid = lo + (hi-lo) / 2;
            int64 sn = a + mid * b;

            if (sn <= t && (mid-l+1)*(sl+sn)/2 <= m*t) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}