#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int q = 0, p1=0,p2=0;
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] == '?') {
            q++;
        } else
            p2 += s2[i]=='+' ? 1 : -1;

        p1 += s1[i]=='+' ? 1 : -1;
    }

    int p = abs(p1-p2);

    if (!q && !p) {
        cout << "1.0" << endl;
        return 0;
    }

    double ans = (double) (q+p) / pow(2.0, (double) q);
    cout.precision(15);
    cout << ans << endl;
    return 0;
}
