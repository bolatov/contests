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
    string start, goal;
    cin >> start >> goal;

    if (start.length() != goal.length()) {
        cout << "NO" << endl;
        return 0;
    }

    if (start.compare(goal) == 0) {
        cout << "YES" << endl;
        return 0;
    }

    if (start.find('1') == string::npos || goal.find('1') == string::npos) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}
