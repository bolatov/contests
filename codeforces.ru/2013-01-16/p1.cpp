#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int k, l, n;
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            cin >> n;
            if (n == 1) {
                l = i, k = j;
            }
        }
    }

    cout << abs(2-k) + abs(2-l) << endl;
}