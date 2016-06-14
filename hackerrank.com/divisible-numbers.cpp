#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
const double EPS = 10e-9;
const double INF = (1LL << 30);

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s = "NOT SOLVED";

    return 0;
}