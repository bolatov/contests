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

// Problem 250
class SkiResortsEasy {
    public:
    int minCost(vector <int> altitude) {
        int minVal = 0;

        for (int i = 1; i < altitude.size(); i++) {
            if (altitude[i] > altitude[i-1]) {
                int diff = altitude[i] - altitude[i-1];
                minVal += diff;
                altitude[i] -= diff;
            }
        }

        return minVal;
    }
};


int main () {
    TheJediTestDiv2 sm;
    return 0;
}

