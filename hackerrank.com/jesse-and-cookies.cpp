#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef int64
#define int64 long long
#endif

void swimUp(vector<int64> &v, int i) {
    int parent = i / 2;
    while (parent > 0 && v[parent] > v[i]) {
        swap(v[parent], v[i]);
        i = parent;
        parent = i / 2;
    }
}

void sinkDown(vector<int64> &v, int i, int sz) {
    int pos = i;
    int left = pos * 2;
    int right = pos * 2 + 1;
    
    if (left < sz && v[left] < v[pos]) pos = left;
    if (right < sz && v[right] < v[pos]) pos = right;
    if (i == pos) return;
    swap(v[i], v[pos]);
    sinkDown(v, pos, sz);
}

int removeTop(vector<int64> &v, int sz) {
    swap(v[1], v[sz-1]);
    sz--;
    sinkDown(v, 1, sz);
    return sz;
}

int main() {
    int N, sz = 1;
    int64 K, val;
    cin >> N >> K;
    vector<int64> v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> val;
        v[sz++] = val;
        swimUp(v, sz - 1);
    }
    
    int cnt = 0;
    while (v[1] < K) {
        if (sz < 3) {
            cnt = -1;        
            break;
        }
        cnt++;
        
        // Least sweet cookie
        int64 i = v[1];
        sz = removeTop(v, sz);
        
        // 2nd least sweet cookie
        int64 j = v[1];
        sz = removeTop(v, sz);
        
        v[sz++] = i + 2LL * j;
        swimUp(v, sz - 1);
    }
    printf("%d\n", cnt);
    return 0;
}
