#include <bits/stdc++.h>

using namespace std;

#ifndef int64
#define int64 long long
#endif

void g(unordered_map<int, int>& mp, int i) {
    if (mp.find(i) == mp.end()) {
        mp[i] = 0;
    }
    mp[i]++;
}

unordered_map<int, int> f(int n) {
    unordered_map<int, int> mp;
    while (n % 2 == 0) {
        g(mp, 2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            g(mp, i);
            n /= i;
        }
    }

    if (n > 2) {
        g(mp, n);
    }
    return mp;
}

// void printMap(unordered_map<int, int> m) {
//     for (auto p : m) {
//         printf("%d -> %d\n", p.first, p.second);
//     }
//     printf("---------------------------------------------\n");
// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    unordered_map<int, int> mn = f(n);
    unordered_map<int, int> mm = f(m);

    // printMap(mn);
    // printMap(mm);

    set<int> st;
    int ans = 0;
    for (auto p : mn) {
        st.insert(p.first);
        if (mm.find(p.first) != mm.end()) {
            ans += abs(p.second - mm[p.first]);
        } else {
            ans += p.second;
        }
    }
    for (auto p : mm) {
        if (st.find(p.first) == st.end()) {
            if (mn.find(p.first) != mn.end()) {
                ans += abs(p.second - mn[p.first]);
                printf("[%d] %d - %d\n", p.first, p.second, mn[p.first]);
            } else {
                ans += p.second;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}