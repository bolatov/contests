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
    int start = N / 2;
    int begin = start;
    int end = start;
    bool up = true;
    for (int i = 0; i < N; ++i)
    {

        for (int j = 0; j < N; ++j)
        {
            if (j >= begin && j <= end) {
                printf("D");
            } else {
                printf("*");
            }
        }
        printf("\n");
        if (begin == 0 && end == N-1) {
            up = false;
        }

        if (up) {
            begin--;
            end++;
        } else {
            begin++;
            end--;
        }
    }

    return 0;
}