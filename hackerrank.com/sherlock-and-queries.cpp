#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define uint64 unsigned long long int

typedef pair<uint64, uint64> pii;

const uint64 MOD = 1e9 + 7;

void printArray(std::vector<uint64> a) {
    for (int i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int n, m, inum;
    cin >> n >> m;
    std::vector<uint64> a(n + 1);
    std::vector<pii> bc(n + 1, pii(0, 0));

    // A
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    // B
    for (int i = 0; i < m; ++i) {
        cin >> bc[i + 1].first;
    }

    // C
    for (int i = 0; i < m; ++i) {
        cin >> bc[i + 1].second;
    }

    // sort(bc.begin(), bc.end());
    for (int j = 1; j <= m; ++j) {
        for (int i = bc[j].first; i <= n; i += bc[j].first) {
            a[i] *= bc[j].second;
            a[i] %= MOD;
        }
    }

    // brute force
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         if (i % b[j] == 0) {
    //             a[i] *= c[j];
    //             a[i] %= MOD;
    //         }
    //     }
    // }

    printArray(a);

    return 0;
}