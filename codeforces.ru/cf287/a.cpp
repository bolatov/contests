#include <bits/stdc++.h>
using namespace std;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    int sum = 0, i;
    for (i = 0; i < n && sum + v[i].first <= k; ++i) {
        sum += v[i].first;
    }
    if (i > 0) {
        cout << i << endl;
        for (int j = 0; j < i; ++j) {
            printf("%d ", v[j].second);
        }
        printf("\n");
    } else {
        puts("0");
    }

    return 0;
}