#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    n /= 10;
    cout << (n * (n + 1) * 100LL + 25LL) << endl;
    return 0;
}