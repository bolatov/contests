#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
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

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
//    int N, T;
//    cin >> N >> T;
//    vector<int> arr(N, 0);
//    for (int i = 0; i < N; i++) {
//        cin >> arr[i];
//    }

//    int range = 0;
//    int i = 0, j = 0;
//    int sum = 0;
//    for (i = 0; i < N; i++) {
//        while (arr[j] + sum <= T && j < N) {
//            sum += arr[j];
//            j++;
//        }
//        range = max(range, j-i);
//        sum -= arr[i];
//    }
//    cout << range << endl;
    // test
    int N, K;
        cin >> N >> K;
        int sum = 0, pipes=0;
        if (N <= K) {
            printf("1\n");
            return 0;
        }

        while(K > 1 && pipes<N) {
            if (pipes+K-1 < N) {
                if (pipes==0) {
                    pipes += K;
                    sum++;
                } else {
                    pipes += K-1;
                    sum++;
                }
                K--;
            }
        }
//        printf("pipes=%d\n", pipes);
        if (pipes == N) {
            printf("%d\n", sum);
        }
        else
            printf("-1\n");

        return 0;
    // end test
}

int p1() {
//    freopen("input.txt", "r", stdin);
    int x, y;
    cin >> x >> y;

    int i = 0, j = 0;
    int xdir = 1, ydir = 0;
    int steps = 1, turns = 0;

    if (x == j && i == y) {
        cout << turns << endl;
        return 0;
    }
//    j += xdir;
//    x += ydir;

    while (true) {
        for (int k = 0; k < steps; k++) {
            j += xdir;
            i += ydir;

            if (x == j && i == y) {
                cout << turns << endl;
                return 0;
            }

        }

        turns++;
        int modv = turns % 4;
        if (modv == 1)      { xdir = 0,  ydir = 1; }
        else if (modv == 2) { xdir = -1, ydir = 0; }
        else if (modv == 3) { xdir = 0,  ydir = -1;}
        else                { xdir = 1,  ydir = 0; }

        if (turns % 2 == 0)
            steps++;

    }

    return 0;
}
