#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;
#define int64 long long

const int64 f = 4LL;
const int64 s = 7LL;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n;
    cin >> n;
    int64 r = 1LL;

    vector<int64> vi = {f, s};
    for (int i = 0; vi[vi.size()-1] < 1e9+7LL; i++) {
        vi.push_back(vi[i]*10LL+4LL);
        vi.push_back(vi[i]*10LL+7LL);
    }

    r = 1;
    for (int i = 0; n > vi[i] && i < (int) vi.size(); ++i)
    {
        r++;
    }
    
    cout << r << endl;
    return 0;
}