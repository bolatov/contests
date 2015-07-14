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

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

// Problem 500
class TeamContestEasy {
    public:
    int worstRank(vector <int> str) {
        int maxRank = 0;

        long myTeam = str[0] + str[1] + str[2];
        myTeam -= min(str[0], min(str[1], str[2]));

        int len = str.size();

        do {
            int tempMax = 0;
            for (int i = 3; i < len; i += 3) {
                long opponent = str[i] + str[i+1] + str[i+2];
                opponent -= min(str[0], min(str[1], str[2]));

                // printf("%d: %d %d %d\n", i, str[i], str[i+1], str[i+2]);

                if (opponent > myTeam) tempMax++;
            }
            // printf("\n");
            maxRank = max(maxRank, tempMax);

        } while (next_combination(str.begin(), str.end()));

        return maxRank+1;
    }
};

int main() {
    TeamContestEasy m;
    vector<int> str = {5, 7, 3, 5, 7, 3, 5, 7, 3};
//     vector<int> str = {570466,958327,816467,17,403,953808,734850,5824,917784,921731,161921,1734,823437,3218,81,932681,2704,981643,1232,475,873323,6558,45660,1813,4714,224,
// 32301,28081,6728,17055,561,15146,842613,5559,1860,783,989,2811,20664,112531,1933,866794,805528,53821,2465,137385,39,2007};
//     cout << m.worstRank(str) << endl;

    str = {610297,849870,523999,6557,976530,731458,7404,795100,147040,110947,159692,40785,4949,2903,1688,37278,620703,28156,16823,1159,12132,971379,5916,1159,988589,
12215,133,1490,911360,920059,544070,40249,514852,852,745070,1105,715897,714696,589133,698317,5683,631612,16453,101000,764881,101,2053,754661};
    // str = {2,2,1,1,3,1,3,2,1,3,1,2,1,2,1};
    cout << m.worstRank(str) << endl;
    return 0;
}

