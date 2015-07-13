#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        unsigned int n;
        cin >> n;
        for (int i = 0; i < 32; i++) {
            n ^= 1 << i;
        }

        cout << n << endl;
    }
    return 0;
}
