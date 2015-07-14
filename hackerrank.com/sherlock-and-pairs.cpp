#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    std::cin >> t;
    while (t-- > 0) {
        cin >> n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (v[i] == v[j])
                    ans += 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
