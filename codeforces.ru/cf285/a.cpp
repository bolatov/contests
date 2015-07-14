#include <bits/stdc++.h>

using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}
int score(int p, int t) { return max(3 * p / 10, p - (p / 250) * t); }
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int misha = score(a, c);
    int vasya = score(b, d);
    if (misha == vasya)
        puts("Tie");
    else if (misha > vasya)
        puts("Misha");
    else
        puts("Vasya");

    return 0;
}
