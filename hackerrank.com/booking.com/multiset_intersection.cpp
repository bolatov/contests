#include <bits/stdc++.h>

using namespace std;

vector<int> findIntersection(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ma, mb;
    for (int ia : a) {
        if (ma.find(ia) == ma.end()) {
            ma[ia] = 0;
        }
        ma[ia]++;
    }
    for (int ib : b) {
        if (mb.find(ib) == mb.end()) {
            mb[ib] = 0;
        }
        mb[ib]++;
    }

    vector<int> v;
    for (auto kv : ma) {
        if (mb.find(kv.first) != mb.end()) {
            int cnt = min(ma[kv.first], mb[kv.first]);
            for (int i = 0; i < cnt; i++) {
                v.push_back(kv.first);
            }
        }
    }
    return v;
}

int main() {
    vector<int> a = {0, 1, 1, 2, 2, 5};
    vector<int> b = {0, 1, 2, 2, 2, 6};

    // intersection of 'a' and 'b'
    vector<int> v = findIntersection(a, b);
    sort(v.begin(), v.end());
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}