#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#ifndef int64
#define int64 unsigned long long
#endif

void p(vector<int> v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> v(n), u(k, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    bool rev = 1;
    int klo = 0, khi = k - 1;
    int nlo = 0, nhi = n - 1;
    while (nlo <= nhi) {
        if (rev) {
            for (int j = khi; j >= klo && nhi >= nlo; --j) {
                if (u[j])
                    khi--;
                u[j] += v[nhi--];
                // printf("%d ", v[nhi--]);
            }
            // printf("\n");
            // printf("REV klo=%d, khi=%d\t", klo, khi);
            // p(u);
        } else {
            for (int j = klo; j <= khi && nlo <= nhi; ++j) {
                if (u[j])
                    klo++;
                u[j] += v[nlo++];
                // printf("%d ", v[nlo++]);
            }
            // printf("\n");
            // printf("FOR klo=%d, khi=%d\t", klo, khi);
            // p(u);
        }
        rev = !rev;
        // p(u);
    }
    int r = 0;
    for (int i : u) {
        r = max(r, i);
    }
    cout << r << endl;

    return 0;
}
