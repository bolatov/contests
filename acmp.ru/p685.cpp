#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    // ltrim
    while (!s.empty() && s[0] == ' ') {
        s = s.substr(1);
    }

    // rtrim
    while (!s.empty() && s[s.size() - 1] == ' ') {
        s = s.substr(0, s.size() - 1);
    }
    int cur = 0;
    vector<int> v;
    for (int i = 0; i < (int)s.size(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            cur = cur * 10 + (s[i] - '0');
        } else if (cur) {
            v.push_back(cur);
            cur = 0;
        }

        if (i + 1 == (int)s.size()) {
            v.push_back(cur);
        }
    }
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        int mx = -1, jmx = -1;
        for (int j = 0; j < 3; ++j) {
            if (v[j] > mx) {
                jmx = j;
                mx = v[j];
            }
        }
        int xm = -1, jxm = -1;
        for (int j = 3; j < 6; ++j) {
            if (v[j] * mx > xm) {
                xm = v[j] * mx;
                jxm = j;
            }
        }
        sum += xm;
        v[jmx] = -1;
        v[jxm] = -1;
    }
    cout << sum << endl;
    return 0;
}