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
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n, k, ki;
        std::vector<bool> v(n, 1);
        scanf(" %d %d", &n, &k);
        for (int i = 0; i < k; ++i) {
            scanf(" %d", &ki);
            v[k - 1] = 0;
        }
    }
    return 0;
}
