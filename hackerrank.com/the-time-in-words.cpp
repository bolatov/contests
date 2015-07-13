#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string toString(int n) {
    string s = "";
    if (n == 0) {
        s += "";
    } else if (n == 1) {
        s += "one";
    } else if (n == 2) {
        s += "two";
    } else if (n == 3) {
        s += "three";
    } else if (n == 4) {
        s += "four";
    } else if (n == 5) {
        s += "five";
    } else if (n == 6) {
        s += "six";
    } else if (n == 7) {
        s += "seven";
    } else if (n == 8) {
        s += "eight";
    } else if (n == 9) {
        s += "nine";
    } else if (n == 10) {
        s += "ten";
    } else if (n == 11) {
        s += "eleven";
    } else if (n == 12) {
        s += "twelve";
    } else if (13 <= n && n <= 19) {
        string t;
        if (n == 13) {
            t = "thir";
        }
        // else if (n == 15){t="fif";}
        else {
            t = toString(n % 10);
        }
        s += t + "teen";
    } else if (n < 30) {
        s += "twenty";
        if (n % 10) {
            s += " " + toString(n % 10);
        }
    }

    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    int h, m;
    cin >> h >> m;
    string ans;
    if (m == 0) {
        ans = toString(h) + " o' clock";
    } else if (m == 15) {
        ans = "quarter past " + toString(h);
    } else if (m == 30) {
        ans = "half past " + toString(h);
    } else if (m == 45) {
        ans = "quarter to " + toString(h + 1);
    } else if (1 <= m && m <= 29) {
        ans = toString(m) + " minute" + (m > 1 ? "s" : "") + " past " +
              toString(h);
    } else if (31 <= m && m <= 59) {
        int diff = 60 - m;
        ans = toString(diff) + " minute" + (diff > 1 ? "s" : "") + " to " +
              toString(h + 1);
    }
    cout << ans << endl;
    return 0;
}