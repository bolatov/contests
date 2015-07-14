#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s;
    int n = 8;
    int a = 0, b = 0;
    while (n--) {
        cin >> s;
        for (char ch : s) {
            switch (ch) {
            case 'Q':
                a += 9;
                break;
            case 'R':
                a += 5;
                break;
            case 'B':
                a += 3;
                break;
            case 'N':
                a += 3;
                break;
            case 'P':
                a += 1;
                break;
            case 'K':
                a += 0;
                break;
            case 'q':
                b += 9;
                break;
            case 'r':
                b += 5;
                break;
            case 'b':
                b += 3;
                break;
            case 'n':
                b += 3;
                break;
            case 'p':
                b += 1;
                break;
            case 'k':
                b += 0;
                break;
            default:
                break;
            }
        }
    }
    if (a == b)
        puts("Draw");
    else if (a > b)
        puts("White");
    else
        puts("Black");
    return 0;
}