#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    std::vector<bool> u(26, 0);
    string s;
    getline(cin, s);
    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z')
            u[ch - 'a'] = 1;
        else if (ch >= 'A' && ch <= 'Z')
            u[ch - 'A'] = 1;
    }

    bool ok = 1;
    for (bool b : u)
        if (!b)
            ok = 0;
    cout << (ok ? "pangram" : "not pangram") << endl;
    return 0;
}
