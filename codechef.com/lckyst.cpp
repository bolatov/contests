#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long z = 0;
        while (n % 10 == 0) {
            z++;
            n /= 10;
        }

        long long lst = n % 10;
        while (lst == 5) {
            n *= 4;

            while (n % 10 == 0) {
                z++;
                n /= 10;
            }
            lst = n % 10;
        }
        printf("%lld", n);
        for (int i = 0; i < z; ++i) {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}