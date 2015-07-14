#include <bits/stdc++.h>

using namespace std;

long long brute_force(long long a, long long b) {
    for (long long i = a; i <= b; ++i) {
        a &= i;
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int itest = 0;
    while (itest++ < t) {
        long long a, b, ans, start;
        cin >> a >> b;
        ans = a;
        start = 1;
        while (start < a) {
            start <<= 1;
        }
        if (start > b) {
            ans = brute_force(a, b);
        }
        for (; start <= b; start <<= 1) {
            ans &= start;
        }
        ans &= b;
        cout << itest << ": " << (ans == brute_force(a, b) ? "-" : "FAILED")
             << endl;
    }
    return 0;
}