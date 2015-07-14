#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    int t, n, ai;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> ai;
            sum += ai - 1;
        }
        printf("%s\n", (sum <= 100 && sum + n >= 100) ? "YES" : "NO");
    }
    return 0;
}
