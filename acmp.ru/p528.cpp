#include <iostream>
using namespace std;

#ifndef int64
#define int64 long long
#endif

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int64 n, k;
    cin >> n >> k;
    int64 asum = (n + n + n * (k - 1)) * k / 2;
    int64 bsum = (1 + 1 + 2 * (k - 1)) * k / 2;
    cout << (asum - bsum + 1) << endl;
    return 0;
}