#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t-- > 0) {
        int M, N;
        cin >> M >> N;
        map<int, int> m;
        int ci;
        for (int i = 0; i < N; ++i) {
            cin >> ci;
            if (m.find(M - ci) != m.end()) {
                printf("%d %d\n", m[M - ci], i + 1);
            } else {
                m[ci] = i + 1;
            }
        }
    }
    return 0;
}
