#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef int64
#define int64 long long
#endif

int m, n, r;
int a[305][305];

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // convert matrix rings to vectors
    /*
        e.g.
        1 2 1 0     --> 0: [1,2,3,4,5,6,7,8,9,0,1,2]
        2 * * 9     --> 1: [*,*,*,*]
        3 * * 8
        4 5 6 7
    */
    vector<vector<int>> vvi;
    for (int pos = 0; pos < min(m, n) / 2; ++pos) {
        vector<int> vi;
        int i = pos, j = pos;
        // [top,left]->[bottom,left]
        for (; i < n - pos; i++) {
            // printf("i=%d,j=%d\n", i, j);
            vi.push_back(a[i][j]);
        }
        i--;
        j++;
        // printf("\n");

        // [bottom,left]->[bottom,right]
        // printf("%d\n", last);
        for (; j < m - pos; j++) {
            // printf("i=%d,j=%d\n", i, j);
            vi.push_back(a[i][j]);
        }
        i--;
        j--;
        // printf("\n");

        // [bottom,right]->[top,right]
        for (; i >= pos; i--) {
            // printf("i=%d,j=%d\n", i, j);
            vi.push_back(a[i][j]);
        }
        i++;
        j--;
        // printf("\n");

        // [top,right]->[top,left]
        for (; j > pos; j--) {
            // printf("i=%d,j=%d\n", i, j);
            vi.push_back(a[i][j]);
        }
        // printf("\n");
        vvi.push_back(vi);
    }

    // printf("Matrix Rings\n");
    // for_each(vvi.begin(), vvi.end(), [](vector<int> &vi) {
    //     for_each(vi.begin(), vi.end(), [](int i) { printf("%d ", i); });
    //     printf("\n");
    // });
    // printf("\n");

    // do rotations with vectors
    // printf("Rotations:\n");
    for (int i = 0; i < (int)vvi.size(); ++i) {
        int len = (int)vvi[i].size();
        vector<int> vnext(vvi[i].size());
        for (int j = 0; j < len; ++j) {
            // printf("j=%d r=%d len=%d, y=%d\n", j, r, len, ((j + r) % len));
            vnext[(j + r) % len] = vvi[i][j];
        }
        vvi[i] = vnext;
        // printf("[%d]: ", i + 1);
        // for_each(vvi[i].begin(), vvi[i].end(), [](int v) { printf("%d ", v);
        // });
        // printf("\n");
    }

    // convert vectors back to matrix rings
    for (int pos = 0; pos < min(m, n) / 2; ++pos) {
        int i = pos, j = pos, k = 0;
        // [top,left]->[bottom,left]
        for (; i < n - pos; i++) {
            // printf("i=%d,j=%d\n", i, j);
            a[i][j] = vvi[pos][k++];
        }
        i--;
        j++;

        // [bottom,left]->[bottom,right]
        for (; j < m - pos; j++) {
            // printf("i=%d,j=%d\n", i, j);
            a[i][j] = vvi[pos][k++];
        }
        i--;
        j--;

        // [bottom,right]->[top,right]
        for (; i >= pos; i--) {
            // printf("i=%d,j=%d\n", i, j);
            a[i][j] = vvi[pos][k++];
        }
        i++;
        j--;

        // [top,right]->[top,left]
        for (; j > pos; j--) {
            // printf("i=%d,j=%d\n", i, j);
            a[i][j] = vvi[pos][k++];
        }
    }

    print();

    return 0;
}
