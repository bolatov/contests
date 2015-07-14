#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int x[26];
    for (int i = 0; i < 26; ++i) {
        cin >> x[i];
    }
    string s;
    cin >> s;
    int n = (int)s.size();
    map<int64, int> cnt[26];
    int64 sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        cerr << (i + 1) << ": " << s[i] << ", " << sum << endl;
        ans += cnt[c][sum];
        sum += x[c];
        cnt[c][sum] += 1;
    }
    // cout << "ans: " << ans << endl;
    return 0;
}