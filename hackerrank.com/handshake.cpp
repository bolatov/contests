#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, ans;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            ans += n - i - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
