#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 1;
    for (char ch : s) {
        if ('A' <= ch && ch <= 'Z') cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
