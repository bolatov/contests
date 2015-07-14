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
void printArray(std::vector<int> v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    std::vector<int> w(n), books(m);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    std::vector<int> counts(n, 0);
    int bi;
    for (int i = 0; i < m; ++i) {
        cin >> bi;
        books[i] = bi - 1;
        counts[bi - 1]++;
    }
    // printf("counts: ");
    // printArray(counts);

    std::vector<char> u(n, 0);
    std::vector<int> vsorted;
    for (int i = 0; i < n; ++i) {
        int minInd = 0;
        int minVal = m;
        for (int j = 0; j < n; ++j) {
            if (!u[j]) {
                if (counts[j] < minVal) {
                    minInd = j;
                    minVal = counts[j];
                } else if (counts[j] == minVal && w[j] < w[minInd]) {
                    minInd = j;
                }
            }
        }
        u[minInd] = 1;
        vsorted.push_back(minInd);
    }
    printf("books: ");
    printArray(books);
    printf("start: ");
    printArray(vsorted);
    int ans = 0;
    for (int book : books) {
        for (int j = vsorted.size() - 1; j >= 0; --j) {
            if (vsorted[j] == book) {
                vsorted[j] = -1;
                vsorted.push_back(book);
                break;
            } else if (vsorted[j] > -1) {
                printf("... + w[%d]\n", vsorted[j]);
                ans += w[vsorted[j]];
            }
        }
        printf("vsorted: ");
        printArray(vsorted);
        printf("ans=%d\n---------------------------\n\n", ans);
    }
    printf("%d\n", ans);

    return 0;
}
