#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    int t1 = x1 + x2 + x3 + x4;
    int t2 = y1 + y2 + y3 + y4;
    puts(t1 == t2 ? "DRAW" : (t1 > t2 ? "1" : "2"));
}