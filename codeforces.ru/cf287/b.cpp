#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long v[5];
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }
    v[0] *= 2;
    long long x = abs(v[3] - v[1]), y = abs(v[4] - v[2]);
    cout << ceil(sqrt(x * x + y * y) / v[0]) << endl;

    return 0;
}