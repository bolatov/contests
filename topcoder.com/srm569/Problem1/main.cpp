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
class TheJediTestDiv2 {
    public:
    int countSupervisors(vector<int> students, int Y, int J) {
        unsigned int N = students.size();
        int total = 0;

        int maxDiff = 0;
        for (int i = 0; i < N; i++) {
            int without = ceil(students[i] / (float) J);
            total += without;

            int with = 0;
            if (students[i] > Y)
                with = (int) ceil( (students[i]-Y) / (float) J);
            maxDiff = max(maxDiff, without-with);
        }


        return max(0, total - maxDiff);
    }
};


int main () {
    TheJediTestDiv2 sm;
    cout << "Problem 250" << endl;
    // 0
//    vector<int> students = {10, 15};
//    cout << sm.countSupervisors(students, 12, 5);

    // 1
//    vector<int> students = {11, 13, 15};
//    cout << sm.countSupervisors(students, 9, 5);

    // 2
//    vector<int> students = {10};
//    cout << sm.countSupervisors(students, 100, 2);

    // 3
//    vector<int> students = {4, 7, 10, 5, 6, 55, 2};
//    cout << sm.countSupervisors(students, 20, 3);
    vector<int> students = {905, 2, 4, 732, 374, 534, 675, 69, 434, 452, 105, 680, 562, 160, 971, 967, 714, 16, 931, 225, 593, 274, 865, 696, 969, 57, 253, 407, 419, 239, 709, 100, 757, 856};
    cout << sm.countSupervisors(students, 392, 65);
    cout << endl;
    return 0;
}

