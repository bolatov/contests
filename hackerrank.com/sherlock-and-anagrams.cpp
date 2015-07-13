#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool eq(std::vector<int> v, std::vector<int> u) {
    int n = (int)v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] != u[i])
            return false;
    }
    return true;
}

vector<int> str2vec(string s) {
    std::vector<int> v(26, 0);
    for (char ch : s) {
        v[ch - 'a']++;
    }
    return v;
}

int main() {
    freopen("input.txt", "r", stdin);
    int ts;
    cin >> ts;
    while (ts--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int len = j - i + 1;
                string pref = s.substr(i, len);
                std::vector<int> pv = str2vec(pref);
                for (int k = i + 1; k < n; ++k) {
                    string sub = s.substr(k, len);
                    std::vector<int> su = str2vec(sub);
                    if (pref.size() == sub.size() && eq(pv, su)) {
                        res++;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
