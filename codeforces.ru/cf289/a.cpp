#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    std::vector<std::vector<int> > v(n, std::vector<int>(n, 1));
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }
    cout << v[n - 1][n - 1] << endl;
    return 0;
}