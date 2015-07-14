#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int t, n, k;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        bool yes = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] + b[i] < k) {
                yes = 0;
                break;
            }
        }
        if (yes)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}