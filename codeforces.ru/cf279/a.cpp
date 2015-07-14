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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int N;
    cin >> N;
    vector<int> t1;
    vector<int> t2;
    vector<int> t3;
    int n;
    for (int i = 1; i <= N; ++i) {
        cin >> n;
        if (n == 1)
            t1.push_back(i);
        else if (n == 2)
            t2.push_back(i);
        else
            t3.push_back(i);
    }

    int st1 = t1.size();
    int st2 = t2.size();
    int st3 = t3.size();
    int sz = min(st1, min(st2, st3));
    cout << sz << endl;
    for (int i = 0; i < sz; ++i) {
        printf("%d %d %d\n", t1[i], t2[i], t3[i]);
    }

    return 0;
}

