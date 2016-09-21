#include <bits/stdc++.h>
using namespace std;

string f(string s) {
    if (s.empty()) {
        return "";
    }
    string t = "";
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            if (cnt % 2) {
                t += c;
            }
            c = s[i];
            cnt = 1;
        }
    }
    if (cnt % 2) {
        t += c;
    }
    return t;
}

int main() {
    string s;
    cin >> s;
    for (string i = s; i != f(i); i = f(i), s = i) {
        ;
    }
    puts(s.empty() ? "Empty String" : s.c_str());
    return 0;
}
