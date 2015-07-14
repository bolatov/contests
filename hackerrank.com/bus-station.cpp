#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

set<int> findFactors(int n) {
    std::set<int> v;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v.insert(i);
            v.insert(n / i);
        }
    }
    return v;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    std::vector<int> v(n);
    int sum = 0, mx = 1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
    }

    for (int i : findFactors(sum)) {
        if (i < mx)
            continue;
        bool yes = 1;
        int capacity = i;
        for (int j = 0; j < n; ++j) {
            capacity -= v[j];
            if (capacity < 0) {
                yes = 0;
                break;
            } else if (capacity == 0 && j != n - 1)
                capacity = i;
        }
        if (yes && capacity == 0)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}