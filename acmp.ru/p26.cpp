#include <iostream>
#include <cmath>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int dxx = dx * dx;
    int dyy = dy * dy;
    puts(dxx + dyy <= (r1 + r2) * (r1 + r2) && (dxx + dyy >= (r1 - r2) * (r1 - r2)) ? "YES" : "NO");
    return 0;
}
