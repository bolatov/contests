#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string s;
    cin >> s;
    vector<int> v(s.size());
    for (int i = 0; i < s.size(); i++) {
        v[i] = s[i] - 'a';
    }

    // for (int i = 0; i < v.size(); i++) {
    //     printf("%d : %d\n", i, v[i]);
    // }

    for (int i = 1; i < s.size() - 1; i++) {
        if (v[i] == v[i - 1]) {
            while (v[i] == v[i - 1] || v[i] == v[i + 1]) {
                v[i] = rand() % 25 + 1;
            }
            // cout << i << ":" << v[i] << endl;
        }
    }
    s = "";
    for (int i : v) {
        s += i + 'a';
    }
    cout << s << endl;

    return 0;
}