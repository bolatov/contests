#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];
int b[1001];

typedef pair<int, int> pii;

int solve(int iter) {}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    cout << solve(n) << endl;
    return 0;
}