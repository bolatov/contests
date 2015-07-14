#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

/*
 * Used RMQ to solve this challenge
 * src:
 * http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor#Range_Minimum_Query_%28RMQ%29
 */

void printArray(std::vector<int> &v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n >> t;
    int blockSize = sqrt(n);
    vector<int> v(n), m;

    // read input
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i % blockSize == 0) {
            m.push_back(v[i]);
        } else {
            int last = m.size() - 1;
            m[last] = min(v[i], m[last]);
        }
    }

    // printf("m: ");
    // printArray(m);

    // read queries
    int i, j;
    while (t-- > 0) {
        cin >> i >> j;
        int ans = 3;
        while (i <= j) {
            if (i % blockSize == 0 && (i + blockSize - 1) <= j) {
                ans = min(ans, m[i / blockSize]);
                i += blockSize;
            } else {
                ans = min(ans, v[i]);
                i++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}