#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, a;
    cin >> n;
    std::vector<int> counts(10000, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        counts[a]++;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        counts[a]--;
    }
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i])
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
