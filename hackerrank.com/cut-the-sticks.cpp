#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > cur) {
            cout << n - i << endl;
            cur = v[i];
        }
    }
    return 0;
}