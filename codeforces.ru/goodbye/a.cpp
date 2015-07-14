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

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, t;
    cin >> n >> t;
    t--;
    std::vector<int> v(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i];
    }
    std::vector<char> u(n, 0);
    int cur = 0;
    while (!u[cur]) {
        u[cur] = 1;
        if (cur == t) {
            puts("YES");
            return 0;
        }
        cur = cur + v[cur];
    }
    puts("NO");
    return 0;
}
