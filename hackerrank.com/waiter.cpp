#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N, Q, V;
    cin >> N >> Q;
    vector<stack<int>> vi(Q + 2, stack<int>());
    while (N--) {
        cin >> V;
        vi[0].push(V);
    }
    vector<bool> u(MAX, 1);
    vector<int> primes;
    for (int i = 2; (int)primes.size() < Q; i++) {
        if (u[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAX; j += i)
                u[j] = 0;
        }
    }

    for (int i = 0; i < (int)primes.size(); i++)
        printf("%d: %d\n", i + 1, primes[i]);

    while (!vi[0].empty()) {
        V = vi[0].top();
        vi[0].pop();

        bool ok = 0;
        for (int i = 0; i < Q && V >= primes[i]; i++) {
            if (V % primes[i] == 0) {
                vi[i + 1].push(V);
                ok = 1;
            }
        }
        if (!ok) vi[vi.size() - 1].push(V);
    }

    for (int i = 1; i < (int)vi.size(); i++) {
        // printf("B_%d:\n", primes[i - 1]);
        while (!vi[i].empty()) {
            // cout << vi[i].top() << endl;
            vi[i].pop();
        }
        // printf("\n\n");
    }

    return 0;
}
