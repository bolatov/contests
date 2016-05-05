#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    string s;
    cin >> n >> s;
    int r = 0;
    string t = "";
    for (int i = 2; i < n; ++i) {
        t = "";
        t += s[i - 2];
        t += s[i - 1];
        t += s[i];
        if (t == "010") {
            s[i] = '1';
            r++;
        }
    }
    cout << r << endl;

    return 0;
}