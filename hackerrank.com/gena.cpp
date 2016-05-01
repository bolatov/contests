#include <bits/stdc++.h>

using namespace std;

const int MAX_HOPS = 100;
int best = INT_MAX;
vector<int> vstate(4, -1);

bool is(vector<int> &c) {
    printf("DEBUG is c.size()=%d, vstate.size()=%d\n", (int)c.size(),
           (int)vstate.size());
    for (int i = 0; i < 4; ++i) {
        printf("c[%d]=%d ?=? vstate[%d]=%d\n", i, c[i], i, vstate[i]);
        if (c[i] != vstate[i]) {
            return 0;
        }
    }
    return 1;
}

bool isb(stack<int> &vi, stack<int> &vj) {
    printf("DEBUG isb\n");
    return !vi.empty() && (vj.empty() || vj.top() > vi.top());
}

void solve(vector<stack<int>> vst, int curHops) {
    printf("DEBUG solve() curHops=%d\n", curHops);
    if (curHops >= MAX_HOPS) {
        printf("curHops=%d >= MAX_HOPS\n", curHops);
        return;
    }

    vector<int> currState(vst.size());
    for (size_t i = 0; i < vst.size(); ++i) {
        currState[i] = vst[i].empty() ? -1 : vst[i].top();
    }

    if (is(currState) && curHops < best) {
        best = curHops;
        return;
    }

    for (size_t i = 0; i < vst.size(); ++i) {
        for (size_t j = 0; j < vst.size(); ++j) {
            if (i != j && isb(vst[i], vst[j])) {
                printf("DEBUG 41\n");
                vst[j].push(vst[i].top());
                vst[i].pop();
                solve(vst, curHops + 1);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, vi;
    cin >> n;
    vector<vector<int>> v(4, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> vi;
        v[vi - 1].push_back(i);
    }

    // for (int i = 0; i < v.size(); ++i) {
    //     printf("v[%d]: ", i);
    //     for (int j = 0; j < v[i].size(); ++j) {
    //         printf("%d ", v[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < 4; ++i) {
        sort(v[i].rbegin(), v[i].rend());
        if (!v[i].empty())
            vstate[i] = v[i][0];
    }

    // for (int i = 0; i < vstate.size(); ++i) {
    //     for (int j = 0; j < vstate[i].size(); ++j) {
    //         printf("%d \n", );
    //     }
    // }
    // printf("\n");
    vector<stack<int>> vst(4, stack<int>());
    for (int i = 3; i >= 0; i--) {
        vst[0].push(i);
    }

    solve(vst, 0);
    cout << best << endl;

    return 0;
}