#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    string s;
    while (t-- > 0) {
        cin >> s;
        int n = s.size();
        if (n % 2) {
            puts("-1");
            continue;
        }
        std::vector<int> a(26, 0), b(26, 0);
        for (int i = 0; i < n / 2; ++i) {
            a[s[i] - 'a']++;
            b[s[i + n / 2]]++;
        }
        int ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            ans += abs(a[i] - b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
