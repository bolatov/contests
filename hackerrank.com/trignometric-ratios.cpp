#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f[20];
void init() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 20; i++) {
        f[i] = i * f[i - 1];
    }
}

double sine(double x) {
    double ans = 0.0;
    int j = 1;
    for (int i = 0; i < 5; ++i) {
        double t = pow(x, (double)j) / (double)f[j];
        ans += (i % 2 ? -1 : 1) * t;
        j += 2;
    }
    return ans;
}

double cosine(double x) {
    double ans = 0;
    int j = 0;
    for (int i = 0; i < 5; ++i) {
        double t = pow(x, (double)j) / f[j];
        ans += (i % 2 ? -1 : 1) * t;
        j += 2;
    }
    return ans;
}

int main() {
    init();
    freopen("input.txt", "r", stdin);
    int n;
    double x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        printf("%.3lf\n%.3lf\n", sine(x), cosine(x));
    }
    return 0;
}
