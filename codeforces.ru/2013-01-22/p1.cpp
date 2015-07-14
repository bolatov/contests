#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;

    char prev = s.at(0);
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (prev == s.at(i)) {
            res++;
        } else {
            prev = s.at(i);
        }
    }
    cout << res << endl;
}
