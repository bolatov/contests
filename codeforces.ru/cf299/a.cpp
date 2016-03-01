#include <bits/stdc++.h>
using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

template <typename T> string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

#define int64 long long

string toString(int n) {
    string s = "";
    if (n == 0) {
        s += "zero";
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
        else if (n == 15){
            t="fif";
        }
        else {
            t = toString(n % 10);
        }
        s += t + (n==18?"een":"teen");
    } else if (n < 30) {
        s += "twenty";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 40) {
        s += "thirty";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 50) {
        s += "forty";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 60) {
        s += "fifty";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 70) {
        s += "sixty";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 80) {
        s += "seventy";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 90) {
        s += "eighty";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    } else if (n < 100) {
        s += "ninety";
        if (n % 10) {
            s += "-" + toString(n % 10);
        }
    }

    return s;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    cout << toString(n) << endl;

    return 0;
}