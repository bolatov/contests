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
    int n;
    int64 ai;
    cin >> n;
    multiset<int64> f, s;
    for (int i = 0; i < n; ++i) {
        cin >> ai;
        f.insert(ai);
        s.insert(ai);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> ai;
        f.erase(f.find(ai));
    }
    ai = *(f.begin());
    cout << ai << endl;
    s.erase(s.find(ai));
    // pp(s);
    for (int i = 0; i < n - 2; ++i) {
        cin >> ai;
        s.erase(s.find(ai));
    }
    ai = *(s.begin());
    cout << ai << endl;
    return 0;
}