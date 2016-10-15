#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 7, k = 30;
    cin >> n >> k;
    printf("%d %d %d\n", k / n, k % n, (n - k % n) % n);
    return 0;
}