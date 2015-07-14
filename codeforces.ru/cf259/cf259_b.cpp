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
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    int pos = 0;

    for (int i = 1; i < N; ++i)
    {
        if (arr[i] < arr[i-1]) {
            cnt++;
            pos = i;
        }
    }

    if (cnt == 0) {
        cout << "0" << endl;
    } else if (cnt == 1) {
        if (arr[0] >= arr[N-1]) {
            cout << (N-pos) << endl;
        } else {
            cout << "-1" << endl;
        }
    } else {
        cout << "-1" << endl;
    }

    return 0;
}