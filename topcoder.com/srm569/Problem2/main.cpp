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

// Problem 500
class TheDeviceDiv2 {
    public:
    string identify(vector<string> plates) {
        string result = "YES";

        unsigned int rows = plates.size();
        if (rows < 2) return "NO";
        unsigned int cols = plates[0].size();
        for (int i = 0; i < cols; i++) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < rows; j++) {
                if (plates[j].at(i) == '1') ones++;
                else                        zeros++;
            }
            if (ones < 2 || zeros == 0) return "NO";
        }
        return result;
    }


};

class PenguinTiles {
    public:
    int minMoves(vector<string> tiles) {
        unsigned int cols = tiles.size();
        unsigned int rows = tiles[0].size();
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (tiles[i].at(j) == '.') {
                    if (i==cols-1 && j==rows-1)
                        return 0;
                    else if (i == 0 || i == cols-1 || j == 0 || j == rows-1)
                        return 1;
                    else
                        return 2;
                }
            }
        }
    }
};

int main () {
    PenguinTiles sm;
    cout << "Problem 500" << endl;
    return 0;
}

