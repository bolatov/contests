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
#include <stdexcept>
using namespace std;

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

std::string int2str( int n )
{
    std::ostringstream result;
    result << n;
    return result.str();
}

int str2int( const std::string& s )
{
    int result;
    std::istringstream ss( s );
    ss >> result;
    if (!ss) throw std::invalid_argument( "StrToInt" );
    return result;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    REP(i, N) {
        int aCost, gCost;
        cin >> aCost >> gCost;
        pair<int, int> p = make_pair(aCost, gCost);
        arr.push_back(p);
    }

    string res = "";
    int aSum = 0, gSum = 0;
    REP(i, N) {
        int aCost = arr[i].first;
        int gCost = arr[i].second;
        if (abs(aSum + aCost - gSum) <= 500) {
            aSum += aCost;
            res += "A";
        } else {
            gSum += gCost;
            res += 'G';
        }
    }

    if (abs(aSum - gSum) <= 500) {
        cout << res << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
