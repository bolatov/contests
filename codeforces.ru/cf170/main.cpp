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

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    string words[N];
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    for (char f = 96; f <= 'z'; f++) {
        for (char s = 96; s <= 'z'; s++) {
            for (char t = 'a'; t <= 'z'; t++) {
                string res = "";
                if (f > 96) res += f;
                if (s > 96) res += s;
                res+= t;

                bool found = true;
                for (int i = 0; i < N; i++) {
                    string w = words[i];
                    if (string::npos != w.find(res)) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    cout << res << endl;
                    return 0;
                }
            }
        }
    }
//    cout << string(arr) << endl;
    return 0;
}
