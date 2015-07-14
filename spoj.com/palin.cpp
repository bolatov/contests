#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

std::string num2str(int n) {
    std::ostringstream result;
    result << n;
    return result.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        N++;
        bool is = false;
        string s = num2str(N);
        int l = 0, r = s.size()-1;
        while (l <= r) {
            if (is) {
                s[l] = '0';
                s[r] = '0';
            } else if (s[l] > s[r]) {
                s[r] = s[l];
                is = true;
            } else if (s[l] < s[r]) {
                s[l] = s[r];
                is = true;
            }
            l++;
            r--;
        }
        cout << s << endl;
    }
    return 0;
}
