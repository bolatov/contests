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
    int n,m;
    cin >> n >> m;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
    }

    set<int> mset;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vs[i][j] > vs[i-1][j]) break;
            else if (vs[i][j] < vs[i-1][j]) {
                mset.insert(j);
            }
        }
    }
    cout << mset.size() << endl;
  return 0;
}
