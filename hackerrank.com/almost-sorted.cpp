#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool isSorted(std::vector<int> &v) {
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] > v[i])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    std::vector<int> v(n), w;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i > 0 && v[i - 1] > v[i])
            w.push_back(i - 1);
    }

    int size = w.size();
    switch (size) {
    case 0:
        puts("yes");
        return 0;
    case 1:
        iter_swap(v.begin() + w[0], v.begin() + w[0] + 1);
        if (isSorted(v)) {
            printf("yes\nswap %d %d\n", w[0] + 1, w[0] + 2);
            return 0;
        }
        break;
    case 2:
        iter_swap(v.begin() + w[0], v.begin() + w[1] + 1);
        if (isSorted(v)) {
            printf("yes\nswap %d %d\n", w[0] + 1, w[1] + 2);
            return 0;
        } else {
            iter_swap(v.begin() + w[0], v.begin() + w[1] + 1);
        }
    default:
        reverse(v.begin() + w[0], v.begin() + w[w.size() - 1] + 2);
        if (isSorted(v)) {
            printf("yes\nreverse %d %d\n", w[0] + 1, w[w.size() - 1] + 2);
            return 0;
        }
        break;
    }

    puts("no");
    return 0;
}