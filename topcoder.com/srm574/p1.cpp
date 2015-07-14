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

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

// Problem 250
class CityMap {
    public:
    string getLegend(vector <string> cityMap, vector <int> POIs) {
        vector<int> buffer(26,0);

        REP(i, cityMap.size()) {
            REP(j, cityMap[i].size()) {
                char c = cityMap[i][j];
                if (c >= 'A' && c <= 'Z') {
                    int val = c-65;
                    buffer[val]++;
                }
            }
        }

        string res = "";
        REP(i, POIs.size()) {
            int p = POIs[i];
            REP(j,buffer.size()) {
                if (buffer[j] == p) {
                    res += (char) (j+65);
                    break;
                }
            }
        }
        return res;
    }
};

int main () {
    printf("Hello 250\n");
    CityMap sm;
    return 0;
}

