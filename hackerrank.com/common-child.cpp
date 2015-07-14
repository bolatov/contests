#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    std::vector<std::vector<int> > m(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1])
                m[i][j] = m[i - 1][j - 1] + 1;
            else
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        }
    }
    cout << m[n][n];
    return 0;
}
