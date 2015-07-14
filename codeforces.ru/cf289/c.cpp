#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#ifndef ll
#define ll long long
#endif

ll next(ll mn, ll sum) {
    for (long long i = mn;; ++i) {
        ll t = 0;
        ll n = i;

        while (n) {
            t += n % 10;
            n /= 10;
        }

        if (t == sum)
            return i;
    }
    return -1LL;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // int n;
    // cin >> n;
    // ll mn = 0, bi;
    // for (int i = 0; i < n; ++i) {
    //     cin >> bi;
    //     mn = next(mn, bi);
    //     cout << mn << endl;
    //     mn++;
    // }
    cout << next(0, 100) << endl;

    return 0;
}