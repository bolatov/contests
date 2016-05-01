#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (mp.find(v[i]) == mp.end()) {
            vector<int> s;
            mp[v[i]] = s;
        }
        mp[v[i]].push_back(i);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (mp.find(v[i] + d) != mp.end()) {
            auto vj = mp[v[i] + d];
            int j = lower_bound(vj.begin(), vj.end(), i) - vj.begin();
            if (j < (int)vj.size() && mp.find(v[i] + 2 * d) != mp.end()) {
                auto vk = mp[v[i] + 2 * d];
                int k = lower_bound(vk.begin(), vk.end(), j) - vk.begin();
                if (k < (int)vk.size()) {
                    r++;
                }
            }
        }
    }
    printf("%d\n", r);
    return 0;
}