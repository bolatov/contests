#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    // unsigned long long int n = 6703734870638684097;
    // unsigned long long int n = 7597026128958891522;
    // unsigned long long int n = 6959712971461184279;
    // unsigned long long int n = 4;
    unsigned long long int n = 2;
    int power = 0;
    while (n > 1) {
        power++;
        n >>= 1;
    }
    cout << power << endl;
    return 0;
}