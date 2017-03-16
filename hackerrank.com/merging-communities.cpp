#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100005

int parent[MAXN];
int sz[MAXN];

void init(int size) {
    for (int i = 1; i <= size; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findParent(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
}

void Union(int u, int v) {
    int uroot = findParent(u);
    int vroot = findParent(v);
    
    if (uroot == vroot) return;
    parent[uroot] = vroot;
    sz[vroot] += sz[uroot];
}

int main() {
    int N, Q, u, v;
    char ch;
    
    cin >> N >> Q;
   
    init(N);
 
    while (Q--) {
        cin >> ch;
        if (ch == 'Q') {
            cin >> u;
            printf("%d\n", sz[findParent(u)]);
        } else {
            cin >> u >> v;
            Union(u, v);
        }
    }
    return 0;
}
