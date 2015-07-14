#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int> > graph(n);
    vector<char> parents(n, -1);
    int s, e;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        s--;
        e--;
        parents[e] = s;
        g[s].push_back(e);
    }

    /*
    Start from leaves to root.
    Gather array of ancestors.
    Sort vertices and by using two pointers count
    similar pairs.
    */

    set<pair<int, int> > pairs;

    // Leaf is a vertex without children
    for (int i = 0; i < g.size(); ++i) {
        if (g[i].empty()) {
            // it is a leaf
            vector<int> ancestors = { i }; // add leaf itself
            for (int p = parents[i]; p != -1; p = parents[p]) {
                ancestors.push_back(p);
            }
            sort(ancestors.begin(), ancestors.end());
            for (int ptr1 = 0, ptr2 = 1; ptr2 < ancestors.size();) {
                s = ancestors[ptr2];
                e = ancestors[ptr1];
                int diff = abs(s - e);
                if (diff == 0) {
                    ptr2++;
                } else if (diff <= t) {
                    pairs.insert(make_pair(e, s));
                    ptr2++;
                } else {
                    ptr1++;
                }
            }
        }
    }
    cout << pairs.size() << endl;
    return 0;
}
