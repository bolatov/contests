#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
    int n;
    cin >> n;
    vector<int64> v;
    int64 r = 0, m;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m % 2) {
            v.push_back(m);
        } else {
            r += m;
        }
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i -= 2) {
        if (i - 1 >= 0) {
            r += v[i];
            r += v[i - 1];
        }
    }
    cout << r << endl;

    return 0;
}
