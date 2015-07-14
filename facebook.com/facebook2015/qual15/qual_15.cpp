#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

void printArray(std::vector<char> v) {
    for (char ch : v) {
        cout << ch;
    }
    cout << " ";
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int itest = 1; itest <= t; itest++) {
        string s;
        cin >> s;
        string smin = s;
        string smax = s;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                swap(s[i], s[j]);
                if (s[0] != '0' && s < smin)
                    smin = s;
                if (s > smax)
                    smax = s;
                swap(s[i], s[j]);
            }
        }
        cout << "Case #" << itest << ": " << smin << " " << smax;

        if (itest != t)
            cout << endl;
    }
    return 0;
}