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
    string s, t;
    cin >> s >> t;

    cout << "s: " << s << endl;
    cout << "t: " <<  t << endl;

    int pos=0;
    for (int i = 0; i < t.size(); i++) {
        if (t.at(i) == s.at(pos)) {
            pos++;
        }
    }

    cout << pos+1 << endl;
    return 0;
}
