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

bool isPalindrome(string s) {
    int len = s.size();
    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-i-1])
            return false;
    }
    return true;
}

std::string num2str(int n) {
    std::ostringstream result;
    result << n;
    return result.str();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output_solution.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        N++;
        string s = num2str(N);
        while (!isPalindrome(s)) {
            s = num2str(++N);
        }
        cout << N << endl;
    }
    return 0;
}
