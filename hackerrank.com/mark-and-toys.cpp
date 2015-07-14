#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    std::vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n && k >= v[i]; ++i) {
        ans += 1;
        k -= v[i];
    }
    cout << ans << endl;
    return 0;
}