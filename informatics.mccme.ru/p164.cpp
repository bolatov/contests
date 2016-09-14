#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, s;
    cin >> n >> s;
    s--;

    vector<vector<int>> vvi(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> vvi[i][j];
        }
    }

    vector<bool> u(n, 0);
    stack<int> st;
    st.push(s);
    int cnt = 0;
    while (!st.empty()) {
        int i = st.top();
        st.pop();
        if (!u[i]) {
            cnt++;
        }
        u[i] = 1;
        for (int j = 0; j < n; j++) {
            if (vvi[i][j] && !u[j]) {
                st.push(j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}