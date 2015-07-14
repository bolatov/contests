#include <set>
#include <map>
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
#include <ctime>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

typedef list<int>       LI;

const double EPS = 10e-9;
const double INF = (1LL << 30);

using namespace std;

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

bool isLeap(int num) {
    if (num % 400 == 0)
        return true;
    if (num % 100 == 0 || num % 4 != 0)
        return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    char str1[10];
    char str2[10];

    cin >> str1 >> str2;

    int year1, month1, day1, year2, month2, day2;

    // 1900:01:01
    sscanf(str1, "%4d:%2d:%2d", &year1, &month1, &day1);
    sscanf(str2, "%4d:%2d:%2d", &year2, &month2, &day2);

    // swap
    if (year1 > year2 || (year1==year2 && month1>month2) || (year1==year2 && month1==month2 && day1>day2)) {
        int tmp = year2;
        year2 = year1;
        year1 = tmp;

        tmp = month2;
        month2 = month1;
        month1 = tmp;

        tmp = day2;
        day2 = day1;
        day1 = tmp;
    }

    map<int,int> m;
    m[1] = 31;
    m[2] = 28;
    m[3] = 31;
    m[4] = 30;
    m[5] = 31;
    m[6] = 30;
    m[7] = 31;
    m[8] = 31;
    m[9] = 30;
    m[10] = 31;
    m[11] = 30;
    m[12] = 31;

    int cnt = 0;
    FOR(year,year1,year2) {
        m[2] = isLeap(year) ? 29 : 28;

        int mStart = 1;
        int mEnd = 12;
        if (year == year1)
            mStart = month1;
        if (year == year2)
            mEnd = month2;

        FOR(month, mStart, mEnd) {
            int dStart = 1;
            int dEnd = m[month];
            if (year == year1 && month == month1)
                dStart = day1;
            if (year == year2 && month == month2)
                dEnd = day2-1;
            FOR(day, dStart, dEnd) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

