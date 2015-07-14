#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#define int64 long long int

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    bool is = 1;
    for (int i = n1, j = n2;;) {
        if (is) {
            i--;
            if (i <= 0) {
                puts("Second");
                break;
            }
        } else {
            j--;
            if (j <= 0) {
                puts("First");
                break;
            }
        }
        is = !is;
    }
    return 0;
}