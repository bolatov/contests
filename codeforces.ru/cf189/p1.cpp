#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    // 1, 14, 144

    if (s[0] != '1') {
        cout << "NO" << endl;
        return 0;
    }

    int f = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] != '4' && s[i] != '1') {
            cout << "NO" << endl;
            return 0;
        }
        if (s[i] == '4') {
            if (f == 2) {
                cout << "NO" << endl;
                return 0;
            }
            f++;
        } else {
            f = 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

