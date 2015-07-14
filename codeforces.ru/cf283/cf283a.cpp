#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >>n;
    int v[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int ans = 10000;
    for (int i = 1; i < n-1; ++i) {
        vector<int> f(&v[0], &v[i]);
        vector<int> s(&v[i+1], &v[n]);
        int minv = 0;
        for (int j = 1; j < f.size(); ++j) {
            minv = max(minv, f[j]-f[j-1]);
        }
        minv = max(minv, s[0]-f[f.size()-1]);
        for (int j = 1; j < s.size(); ++j) {
            minv = max(minv, s[j]-s[j-1]);
        }
        ans = min(ans, minv);
    }
    cout << ans << endl;

    return 0;
}
