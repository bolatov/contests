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

#define REP(x, n) for(int x=0; x<(n); ++x)

using namespace std;

void task1() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int h,m,ph=-1,pm,maxd=0,d=1;
    REP(i, n) {
        cin >> h >> m;
        if (m==pm && h==ph) d++;
        else d = 1;

        ph=h;
        pm=m;
        maxd=max(maxd,d);
    }
    printf("%d\n", maxd);
}

int main() {
    task1();
    return 0;
}
