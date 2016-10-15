#include <bits/stdc++.h>

using namespace std;

/**
 * How do you remove repeated values from an int array,
 * returning the resultant array in the same order as original?
 */
vector<int> removeDuplicates(vector<int>& v) {
    set<int> visited;
    int current = 0;
    int size = (int)v.size();
    for (int i = 0; i < size; i++) {
        if (visited.find(v[i]) == visited.end()) {
            v[current++] = v[i];
            visited.insert(v[i]);
        }
    }

    for (; size > current; size--) {
        v.erase(v.begin() + size - 1);
    }

    return v;
}

int main() {
    vector<int> v = {1, 1, 0, 1, 1, 2, 0, 2};
    v = removeDuplicates(v);
    // should output [1, 0, 2]
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}