#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; ++i) {
        printf("%d %d ", v[i], v[n - i - 1]);
    }
    if (n % 2)
        printf("%d", v[n / 2]);
    printf("\n");

    return 0;
}