#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vvi(n, vector<int>());
    int p, q;
    for (int i = 0; i < m; ++i) {
        cin >> p >> q;
        p--;
        q--;
        vvi[p].push_back(q);
        vvi[q].push_back(p);
    }

    vector<int> vc(n, -1);
    for (int i = 0; i < n; ++i) {
        if (vc[i] > -1) {
            continue;
        }

        queue<int> qu;
        qu.push(i);
        vc[i] = 1;
        while (!qu.empty()) {
            int k = qu.front();
            qu.pop();

            for (int child : vvi[k]) {
                if (vc[child] == -1) {
                    vc[child] = 1 - vc[k];
                    qu.push(child);
                } else if (vc[child] == vc[k]) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        if (vc[i] <= 0) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}