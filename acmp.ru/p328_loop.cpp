#include <iostream>
#include <cmath>
using namespace std;

#ifndef int64
#define int64 long long int
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n;
    cin >> n;

    int64 sum = 0;
    for (int64 i = 0; i <= n; ++i) {
        for (int64 j = 0; j <= n; ++j) {
            if (j < i) {
                // printf("-%lld\t-%lld\n", i, j);
            } else {
                printf(" %lld\t %lld\n", i, j);
                sum += i + j;
            }
        }
        printf("\n");
    }
    cout << sum << endl;

    return 0;
}