#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 107, 4};
    int x = 0;
    for (int i : v) {
        x ^= i;
    }
    cout << x << endl;

    return 0;
}
