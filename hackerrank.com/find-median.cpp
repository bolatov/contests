#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int partition(std::vector<int> &v, int l, int r) {
    // printf("partition: lo=%d, hi=%d\n", l, r);
    int p = r - 1;
    int index = l;
    for (int i = l; i < r; ++i) {
        if (v[i] < v[p]) {
            int t = v[i];
            v[i] = v[index];
            v[index] = t;
            index++;
        }
    }
    int t = v[index];
    v[index] = v[p];
    v[p] = t;
    p = index;

    return p;
}

void printArray(std::vector<int> &v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}

void printArrayPivot(std::vector<int> &v, int k) {
    for (int i = 0; i < v.size(); i++) {
        if (i == k)
            printf("[%d] ", i);
        else
            printf("%d ", i);
    }
    printf("\n");
}

int bruteForce(std::vector<int> v, int k) {
    sort(v.begin(), v.end());
    return v[k];
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int itest = 1; itest <= t; itest++) {
        int n;
        cin >> n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int mid = (n % 2 == 0) ? n / 2 - 1 : n / 2;
        int lo = 0, hi = n;
        int runs = 0;
        while (hi - lo > 1) {
            runs++;
            int p = partition(v, lo, hi);

            if (p == mid)
                break;

            // printArrayPivot(v, p);

            if (mid < p)
                hi = p;
            else
                lo = p + 1;
        }
        printf("%d\n", v[mid]);
        int pb = bruteForce(v, mid);
        if (v[mid] != pb) {
            printf("FAILED, expected: %d\n", pb);
            sort(v.begin(), v.end());
            printArray(v);
        } else {
            printf("%d PASSED, runs=%d\n", itest, runs);
            // printArrayPivot(v, mid);
        }
    }
    return 0;
}
