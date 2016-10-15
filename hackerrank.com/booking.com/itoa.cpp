#include <bits/stdc++.h>

using namespace std;

string itoa(int n) {
    string s = "";
    while (n) {
        s += to_string(n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    cout << itoa(4725) << endl;
    return 0;
}