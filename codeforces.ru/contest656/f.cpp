#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif
int GCD(int a, int b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
int LCM(int a, int b) { return a * (b / GCD(a, b)); }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    cout << s[1] << s[2] << endl;

    return 0;
}