#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, ni;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ni;
            if (ni) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int s, d;
    cin >> s >> d;
    s--;
    d--;

    if (s == d) {
        puts("0");
        return 0;
    }

    vector<int> dp(n, INF);
    vector<int> ps(n, -1);
    vector<bool> u(n, 0);
    dp[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int k = q.front();
        q.pop();
        u[k] = 1;
        for (int child : g[k]) {
            if (!u[child] && dp[k] + 1 < dp[child]) {
                ps[child] = k;
                dp[child] = dp[k] + 1;
                q.push(child);
            }
        }
    }

    if (dp[d] < INF) {
        stack<int> st;
        for (int cur = d; cur > -1; cur = ps[cur]) {
            st.push(cur);
        }
        printf("%zu\n", st.size() - 1);
        while (!st.empty()) {
            printf("%d ", st.top() + 1);
            st.pop();
        }
        printf("\n");
    } else {
        puts("-1");
    }

    return 0;
}