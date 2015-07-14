#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

vector<string> v = {
    "1111110",  // 0
    "1100000",
    "1101101",
    "1111001",
    "0110011", // 4
    "1011011", // 5
    "1011111", // 6
    "1110000", // 7
    "1111111", // 8
    "1111011", // 9
};

int solve(string s, int i) {
    int index = s[i]-'0';
    string si = v[index];
    int res = 0;
    for (int j = 0; j < v.size(); ++j) {
        bool possible = true;
        for (int k = 0; k < v[j].size(); ++k) {
            if (v[j][k] == '0' && si[k] == '1') {
                possible = false;
                break;
            }
        }
        if (possible) {
            res++;
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    cout << solve(s,0) * solve(s,1) << endl;
    return 0;
}

