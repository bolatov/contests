#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void median(vector<char> &s, vector<int> &X) {
    multiset<int> si;
    for (int i = 0; i < s.size(); ++i) {
        bool isPrint = true;
        switch (s[i]) {
        case 'a':
            si.insert(X[i]);
            break;
        case 'r':
            multiset<int>::iterator it = si.find(X[i]);
            if (it == si.end())
                isPrint = false;
            else {
                si.erase(it);
            }
            break;
        }

        int size = si.size();
        if (isPrint && size > 0) {
            int m1 = size / 2, m2 = size / 2;
            if (size % 2 == 0) {
                m1 = size / 2 - 1;
            }

            multiset<int>::iterator it = si.begin();
            advance(it, m1);
            double v1 = *it;
            advance(it, m2 - m1);
            double v2 = *it;

            // multiset<int>::iterator it;
            // int j;
            // double v1, v2;
            // for (it = si.begin(), j = 0; it != si.end(); ++it, ++j) {
            //     if (j == m1) {
            //         v1 = *it;
            //     }
            //     if (j == m2) {
            //         v2 = *it;
            //         break;
            //     }
            // }
            double avg = (v1 + v2) / 2;
            string str = to_string(avg);
            str.erase(str.find_last_not_of('0') + 1, string::npos);
            if (str[str.size() - 1] == '.')
                str.erase(str.size() - 1, 1);
            cout << str << endl;
        } else {
            puts("Wrong!");
        }
    }
}
int main(void) {

    // Helpers for input and output

    int N;
    cin >> N;

    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for (int i = 0; i < N; i++) {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}
