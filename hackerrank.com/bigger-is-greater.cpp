#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sortStr(string &s) {
    while (true) {
        bool swapped = false;
        for (int j = 1; j < s.size(); ++j) {
            if (s[j - 1] > s[j]) {
                swap(s[j - 1], s[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    string s;
    cin >> t;
    while (t-- > 0) {
        cin >> s;
        string ans = s;
        sortStr(ans);
        for (int i = 0; i < s.size(); ++i) {
            bool found = false;
            for (int j = i + 1; j < s.size(); ++j) {
                swap(ans[i], ans[j]);
                if (ans > s) {
                    found = true;
                    break;
                } else {
                    swap(ans[i], ans[j]);
                }
            }
            if (found)
                break;
        }
        if (s == ans)
            ans = "no answer";
        cout << ans << endl;
    }
    return 0;
}
