#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    string s;
    while (t-- > 0) {
        cin >> s;
        int index = -1, n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) {
                string is = s;
                is.erase(i, 1);
                if (check(is)) {
                    index = i;
                    break;
                }

                is = s;
                is.erase(n - i - 1, 1);
                if (check(is)) {
                    index = n - i - 1;
                    break;
                }
            }
        }
        cout << index << endl;
    }
    return 0;
}
