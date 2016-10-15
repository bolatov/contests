#include <iostream>
using namespace std;

int main() {
    int v = 60, t = 2;
    cin >> v >> t;
    cout << ((v * t) % 109 + 109) % 109 + 1 << endl;
    return 0;
}