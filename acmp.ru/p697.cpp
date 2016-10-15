#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double l, w, h;
    cin >> l >> w >> h;
    printf("%.0f\n", ceil((2 * l * h + 2 * h * w) / 16));
    return 0;
}