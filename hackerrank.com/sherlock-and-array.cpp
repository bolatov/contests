#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void printArray(string prefix, std::vector<long long> &v) {
    cout << prefix << ": ";
    for (long long i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int t, n;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        std::vector<long long> v(n), inc(n, 0), dec(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        // printArray("input", v);

        for (int i = 1; i < n; ++i) {
            inc[i] += inc[i - 1] + v[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            dec[i] += dec[i + 1] + v[i + 1];
        }
        // printArray("inc", inc);
        // printArray("dec", dec);
        int l, r;
        bool yes = 0;
        for (int i = 0; i < n; ++i) {
            l = (i == 0) ? 0 : inc[i];
            r = (i == n - 1) ? 0 : dec[i];
            if (l == r) {
                yes = 1;
                break;
            }
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}