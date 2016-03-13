#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef int64
#define int64 long long
#endif

bool pairCompare(const std::pair<int64, int> &p1,
                 const std::pair<int64, int> &p2) {
    return p1.first > p2.first;
}

const int MX_VAL = 1e5 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    int64 ni;
    cin >> n;
    vector<int64> cnt(MX_VAL, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ni;
        cnt[ni]++;
    }
    vector<pair<int64, int>> vp(n);
    for (int i = 0; i < MX_VAL; ++i) {
        if (cnt[i] > 0) {
            vp.push_back(make_pair(i * cnt[i], i));
        }
    }
    sort(vp.begin(), vp.end(), pairCompare);

    vector<bool> u(MX_VAL, 0);
    int64 ans = 0;
    for (auto p : vp) {
        int64 w = p.first;
        int i = p.second;
        if (!u[i]) {
            u[i] = 1;
            ans += w;
            if (i - 1 >= 0) {
                u[i - 1] = 1;
            }
            if (i + 1 < MX_VAL) {
                u[i + 1] = 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}