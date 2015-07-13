#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, k;
    string s;
    cin >> n >> k >> s;
    string r(s.end() - 1, s.end());
    int cnt = r[0] == '1';
    for (int i = (int)s.size() - 2; (int)r.size() < n; --i) {
        if ((s[i] == '1') ^ (cnt % 2)) {
            cnt++;
            r += "1";
        } else {
            r += "0";
        }

        int sz = (int)r.size();
        // test
        // printf("s[%d]=%c, cnt=%d => %c\n", (i + 1), s[i], cnt, r[sz - 1]);
        // cout << r << endl
        //      << endl;
        // end test

        if (sz > k - 1) {
            cnt -= r[sz - k] == '1';
        }
    }
    reverse(r.begin(), r.end());
    cout << r << endl;
    return 0;
}
