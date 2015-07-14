#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#define int64 long long int

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    vector<vector<int> > vmax;
    int mx = 0;
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int mn = n;
                for (int k = i; k <= j; ++k) {
                    mn = min(mn, v[k]);
                }
                sum += mn;
            }
        }
        if (sum == mx) {
            vector<int> cur(v);
            vmax.push_back(cur);
        } else if (sum > mx) {
            mx = sum;
            vmax.clear();
            vector<int> cur(v);
            vmax.push_back(cur);
        }

    } while (next_permutation(v.begin(), v.end()));
    vector<int> vm = vmax[m - 1];
    for_each(vm.begin(), vm.end(), [](int i) { printf("%d ", i); });
    printf("\n");
    return 0;
}