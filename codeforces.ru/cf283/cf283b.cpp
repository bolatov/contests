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

template <typename T>
string toString(T t) {
  stringstream ss;
  ss << t;
  return ss.str();
}

string solve(string& s, string& t) {
    int n = s.size();
    for (int k = 0; k < n; ++k) {
        string p = "";
       p += t.substr(k,n);
       p += t.substr(0,k);
       if (p < s) s = p;
    }
    return s;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
    int n; string s;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(s[i]-'0');
    }

    for (int i = 0; i < 10; ++i) {
        string si = "";
        for (int j = 0; j < n; ++j) {
            si += ((v[j]+i) % 10) + '0';
        }
        s = solve(s, si);
    }

    cout << s << endl;

    return 0;
}
