#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int ts;
    cin >> ts;
    while (ts--) {
        string s;
        cin >> s;

        string r = "no answer";
        int pivot = -1;
        for (int i = (int)s.size() - 1; i > 0; i--) {
            if (s[i] > s[i - 1]) {
                pivot = i - 1;
                for (int j = (int)s.size() - 1; j > pivot; --j) {
                    if (s[j] > s[pivot]) {
                        swap(s[j], s[pivot]);
                        reverse(s.begin() + i, s.end());
                        r = s;
                        break;
                    }
                }
                break;
            }
        }
        cout << r << endl;
    }
    return 0;
}
