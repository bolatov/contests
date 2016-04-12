#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif
int GCD(int a, int b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
int LCM(int a, int b) { return a * (b / GCD(a, b)); }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int F, I, T;
    cin >> F >> I >> T;
    vector<string> vs(F);
    for (int i = 0; i < F; ++i) {
        cin >> vs[i];
    }
    int ret = 0;
    for (int i = 0; i < I; ++i) {
        int cnt = 0;
        for (size_t j = 0; j < vs.size(); ++j) {
            if (vs[j][i] == 'Y')
                cnt++;
        }
        ret += cnt >= T;
    }
    cout << ret << endl;

    return 0;
}