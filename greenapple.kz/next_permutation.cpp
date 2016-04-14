#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void prv(vector<int> &v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}

bool nextPermutation(vector<int> &v) {
    int n = (int)v.size();
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            // find min element in right part
            // that is greater than v[i]
            int k = i + 1;
            int minVj = v[k];
            for (int j = i + 1; j < n; ++j) {
                if (v[j] > v[i] && v[j] < minVj) {
                    k = j;
                    minVj = v[j];
                }
            }
            iter_swap(v.begin() + i, v.begin() + k);

            // reverse the right part
            reverse(v.begin() + i + 1, v.end());

            return true;
        }
    }
    return false;
}

int main() {
    int n = 5;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    int i = 1;
    printf("[%d]: ", i);
    prv(v);
    while (nextPermutation(v)) {
        printf("[%d]: ", ++i);
        prv(v);
    }

    return 0;
}