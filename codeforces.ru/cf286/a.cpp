#include <bits/stdc++.h>
using namespace std;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

bool is(string p) {
    int pn = (int)p.size();
    for (int j = 0; j < pn / 2; ++j) {
        if (p[j] != p[pn - j - 1])
            return 0;
    }
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;

    for (char ch : s) {
        for (int i = 0; i < (int)s.size(); ++i) {
            string p = s.substr(0, i + 1);
            p += toString(ch);
            p += s.substr(i + 1);

            if (is(p)) {
                cout << p << endl;
                return 0;
            }
        }

        string p = toString(ch) + s;
        if (is(p)) {
            cout << p << endl;
            return 0;
        }
        p = s + toString(ch);
        if (is(p)) {
            cout << p << endl;
            return 0;
        }
    }

    puts("NA");

    return 0;
}