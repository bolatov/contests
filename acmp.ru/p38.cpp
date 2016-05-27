#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int64 left, right;
int64 fx(vector<int> &v, int lo, int hi) {
    if (hi - lo == 1) {
        return max(v[hi], v[lo]);
    }
    left = v[lo] + fx(v, lo + 1, hi);
    right = v[hi]+ fx(v, lo, hi-1));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    int64 sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    int64 f = fx(v, 0, n - 1);
    int64 s = sum - f;
    if (f > s) {
        puts("1");
    } else if (f < s) {
        puts("2");
    } else {
        puts("0");
    }
    return 0;
}