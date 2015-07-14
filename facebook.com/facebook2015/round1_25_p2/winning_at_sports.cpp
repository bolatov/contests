#include <iostream>
#include <cstdio>

using namespace std;
const int MOD = 1e9 + 7;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, sc1, sc2;
    scanf("%d\n", &t);

    for (int itest = 1; itest <= t; ++itest) {
        scanf("%d-%d\n", &sc1, &sc2);
        int ans1 = solve1(sc1, sc2), ans2 = solve();

        printf("Case #%d: %d %d\n", itest, ans1, ans2);
    }
    return 0;
}