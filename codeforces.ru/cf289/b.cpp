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
    int n, k, ai;
    cin >> n >> k;
    vector<vector<int> > b(n, vector<int>(k, 0));
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        int ik = 0;
        for (int j = 0; j < ai; ++j) {
            b[i][ik]++;
            ik = (ik + 1) % k;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int ik = 0; ik < k; ++ik) {
                if (abs(b[i][ik] - b[j][ik]) > 1) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int ik = 0; ik < b[i][j]; ++ik) {
                printf("%d ", j + 1);
            }
        }
        cout << endl;
    }
    return 0;
}