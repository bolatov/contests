#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string p = "31415926535897932384626433833";
bool check(string s) {
    // cout << "check: " << s << endl;
    if (s.size() > p.size() || s.empty()) {
        return false;
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != p[i])
            return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    getchar();
    string s, t;
    int cnt;
    string yes = "It's a pi song.", no = "It's not a pi song.";
    while (n--) {
        getline(cin, s);
        // cout << "string: " << s << endl;
        int len = (int)s.size();
        t = "";
        cnt = 0;
        for (int i = 0; i < len; ++i) {
            char ch = s[i];
            if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')) {
                cnt++;
            } else if (cnt > 0) {
                t += to_string(cnt);
                cnt = 0;
            }

            if (i == len - 1 && cnt > 0)
                t += to_string(cnt);
        }
        cout << (check(t) ? yes : no) << endl;
    }
    return 0;
}