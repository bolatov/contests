#include <iostream>
#include <vector>

using namespace std;

void quickSort(std::vector<int> &v, int l, int r) {
    if (l >= r - 1)
        return;

    int p = r - 1;
    int index = l;
    for (int i = l; i < p; ++i) {
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

    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");

    quickSort(v, l, p);
    quickSort(v, p + 1, r);
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    quickSort(v, 0, n);
    return 0;
}