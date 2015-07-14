#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    std::vector<int> v(26, 0);
    for (char ch : s) {
        v[ch - 'a']++;
    }
    for (char ch : t) {
        v[ch - 'a']--;
    }
    int ans = 0;
    for (int i : v) {
        ans += abs(i);
    }
    cout << ans << endl;

    return 0;
}