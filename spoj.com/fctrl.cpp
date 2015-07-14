#include <iostream>
#include <vector>
#include <cstdio>

#define PB push_back

using namespace std;

typedef long long LL;
typedef vector<LL> VLL;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        LL ans = 0;
        while (N) {
            ans += N / 5;
            N /= 5;
        }
        cout << ans << endl;
    }

    return 0;
}

