#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int n, k, q;
    cin >> n >> k >> q;
    k %= n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int query;
    for (int i = 0; i < q; ++i) {
        cin >> query;
        // cout << v[n - ((query - k) % n)] << endl;
        int index = query - k;
        if (index < 0)
            index += n;
        cout << v[index] << endl;
    }
    // puts("---------");
    // int arr[3] = { 2, 3, 4 };
    // for (int i = 0; i < 3; ++i) {
    //     printf("%d --> %d\n", arr[i], arr[i] % 3);
    // }
    return 0;
}