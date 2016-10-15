#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    cout << (h2 - h1) * 60 * 60 + (m2 - m1) * 60 + (s2 - s1) << endl;
    return 0;
}