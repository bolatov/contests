#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define uint64 unsigned long long int

uint64 prevPower(uint64 x) {
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x = x | (x >> 32);
    return x - (x >> 1);
}

bool isPowerOfTwo(uint64 n) { return n && !(n & (n - 1)); }

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t-- > 0) {
        uint64 n;
        cin >> n;
        int moves = 0;
        while (n != 1) {
            if (!isPowerOfTwo(n)) {
                n = prevPower(n);
            }
            n >>= 1;
            cout << "n: " << n << endl;
            moves++;
        }
        cout << (moves % 2 ? "Louise" : "Richard") << endl;
    }
    return 0;
}
