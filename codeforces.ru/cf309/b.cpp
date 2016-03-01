#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vs[i];
    }
    sort(vs.begin(), vs.end());
    int res = 1, cnt = 1;
    for (int i = 1; i < (int) vs.size(); ++i)
    {
        if (vs[i] == vs[i-1]) cnt++;
        else cnt = 1;
        res = max(cnt, res);
    }
    cout << res << endl;
    return 0;
}