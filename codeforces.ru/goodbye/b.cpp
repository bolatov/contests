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

void printArray(std::vector<int> &v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    std::vector<int> v(n);
    std::vector<string> vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
    }
    // printArray(v);
    for (int k = 0; k < n; ++k) {

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (v[i] > v[j] && vs[i][j] == '1') {
                    // printf("%d %d\n", i + 1, j + 1);
                    int t = v[i];
                    v[i] = v[j];
                    v[j] = t;
                    // printArray(v);
                }
            }
        }
    }

    printArray(v);

    return 0;
}
