#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int N, a ,b;
    cin >> N;
    map<int, int> m1, m2;
    vector<int> arr(N, -1);
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        m1[a] = b;
        m2[b] = a;
    }

    int i = 1;
    map<int, int>::iterator it = m1.find(0);
    while (it != m1.end() && i < N) {
        arr[i] = it->second;
        it = m1.find(arr[i]);
        i += 2;
    }

    i = N-2;
    it = m2.find(0);
    while (it != m2.end() && i >= 0) {
        arr[i] = it->second;
        it = m2.find(arr[i]);
        i -= 2;
    }

    // 0, N-1
    if (N % 2 == 1) {
        int v = -1;
        for (it = m1.begin(); it != m1.end(); ++it) {
            if (m2.find(it->first) == m2.end()) {
                v = it->first;
                break;
            }
        }

        i = 0;
        while (i < N) {
            arr[i] = v;
            v = m1[v];
            i += 2;
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

