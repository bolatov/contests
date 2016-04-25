#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string s, t;
    map<string, string> m;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        m[s] = t;
    }
    while (cin >> s) {
        if (m.find(s) != m.end())
            cout << s << "=" << m[s] << endl;
        else
            puts("Not found");
    }
    return 0;
}
