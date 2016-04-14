#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

template <typename T> void pv(vector<T> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    string ab = "AB", ba = "BA";
    size_t p = s.find(ab);
    size_t q = (p == string::npos) ? string::npos : s.find(ba, p + 2);
    bool ok1 = p != string::npos && q != string::npos;
    // printf("1. p=%d, q=%d\n", p, q);

    size_t x = s.find(ba);
    size_t y = (x == string::npos) ? string::npos : s.find(ab, x + 2);
    bool ok2 = x != string::npos && y != string::npos;
    // printf("2. x=%d, y=%d\n", x, y);
    puts(ok1 || ok2 ? "YES" : "NO");
    return 0;
}