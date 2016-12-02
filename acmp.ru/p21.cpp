#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    while (!s.empty() && s[0] == ' ') {
        s = s.substr(1);
    }
    while (!s.empty() && s[s.size() - 1] == ' ') {
        s = s.substr(0, s.size() - 1);
    }
    int mn = INT_MAX, mx = INT_MIN;
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            cur = cur * 10 + (s[i] - '0');
        } else if (cur) {
            mn = min(cur, mn);
            mx = max(cur, mx);
            cur = 0;
        }

        if (i + 1 == (int)s.size()) {
            mn = min(cur, mn);
            mx = max(cur, mx);
        }
    }
    cout << abs(mx - mn) << endl;
    return 0;
}