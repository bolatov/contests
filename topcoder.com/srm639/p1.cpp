#include <set>
#include <map>
#include <unordered_map>
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

class ElectronicPetEasy {
public:
    string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
        string easy = "Easy";
        string difficult = "Difficult";

        set<int> pset;
        for (int i = 0; i < t1; i++) {
            pset.insert(st1);
            st1 += p1;
        }

        for (int i = 0; i < t2; i++) {
            if (pset.find(st2) != pset.end())
                return difficult;
            st2 += p2;
        }

        return easy;
    }
};

int main() {
    ElectronicPetEasy s;

    cout << s.isDifficult(3,
                          3,
                          3,
                          5,
                          2,
                          2) << endl;

    return 0;
}

