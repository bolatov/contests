#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef uint64
#define uint64 unsigned long long int
#endif

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    string sl = "Louise", sr = "Richard";
    while (t--) {
        uint64 n;
        cin >> n;
        // printf("N_start=%llu\n", n);
        int i = 0;
        for (i = 0; n > 1 && i < 100; i++) {
            // is power of two?
            int cnt = 0, pos = -1;
            for (int j = 0; j < 64; j++) {
                if (n & (1ULL << j)) {
                    // printf("\t%d bit is set in N=%llu\n", j, n);
                    cnt++;
                    pos = j;
                }
            }
            // printf("\tcnt=%d\n", cnt);
            if (cnt == 1) {
                n -= n / 2ULL;
                // printf("\tyes, N=%llu\n", n);
            } else {
                n -= 1ULL << (pos);
                // printf("\tno, N=%llu\n", n);
            }
            // printf("========================\n");
        }
        // printf("N_final=%llu\n", n);
        cout << (i % 2 ? sl : sr) << endl;
    }
    return 0;
}
