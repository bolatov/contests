#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int find(vector<int> &v, int i) {
    if (v[i] == i) return i;
    return find(v, v[i]);
}

void u_nion(vector<int> &v, int i, int j) {
    int iroot = find(v, i);
    int jroot = find(v, j);
    v[iroot] = jroot;
}

void prv(string s, vector<int> &v) {
    printf("%s", s.c_str());
    for (int i : v) printf(" %d", i + 1);
    printf("\n");
}

void compress(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        v[i] = find(v, i);
    }
}

int main() {
    
    int N, bi, gi;
    cin >> N;
    vector<int> v(2 * N);
    for (int i = 0; i < (int) v.size(); i++) v[i] = i;
    for (int i = 0; i < N; i++) {
        cin >> bi >> gi;
        bi--;
        gi--;
        u_nion(v, bi, gi);
    }
    compress(v);
    //prv("v:", v);
    
    vector<int> cnt(v.size(), 0);
    for (int i : v) cnt[i]++;
    int mx = 0, mn = INT_MAX;
    for (int i : cnt) {
        mx = max(mx, i);
        if (i > 1) mn = min(mn, i);
    }
    printf("%d %d\n", mn, mx);
    
    return 0;
}
