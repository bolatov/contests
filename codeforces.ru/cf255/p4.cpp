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
#include <functional>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push_front
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
typedef pair<PLL, LL> PLLLL;

typedef list<int>       LI;

const double EPS = 10e-9;
const double INF = (1LL << 30);

using namespace std;

std::string num2str( LL n )
{
    std::ostringstream result;
    result << n;
    return result.str();
}

LL str2num( const std::string& s )
{
    LL result;
    std::istringstream ss( s );
    ss >> result;
    if (!ss) throw std::invalid_argument( "StrToInt" );
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int N, M, K, P;
    cin >> N >> M >> K >> P;
    VVI m(N,VI(M,0));

    map<int,int > rows;
    map<int,int > cols;

    REP(i,N) {
        int sum = 0;
        REP(j,M) {
            cin >> m[i][j];
            sum += m[i][j];
        }
        rows[i] = sum;
    }

    REP(j,M) {
        int sum = 0;
        REP(i,N) {
            sum += m[i][j];
        }
        cols[j] = sum;
    }

    int res = 0;
    REP(i,K) {
        int maxRows = max(rows.cbegin()->second, rows.rbegin()->second);
        int maxCols = max(cols.cbegin()->second, cols.rbegin()->second);
        int local = max(maxRows, maxCols);
//        res = max(res, res + local);
        res += local;

        if (maxRows > maxCols) {
            bool cb = rows.cbegin()->second > rows.rbegin()->second;;
            int key = cb ? rows.cbegin()->first : rows.rbegin()->first;
            int value = cb ? rows.cbegin()->second : rows.rbegin()->second;
            rows[key] = value - (M*P);
            for (map<int,int>::iterator it = cols.begin(); it != cols.end(); ++it) {
                cols[it->first] = it->second - P;
            }
//            printf("row=%d\n",key+1);
        } else {
            bool cb = cols.cbegin()->second > cols.rbegin()->second;
            int key = cb ? cols.cbegin()->first : cols.rbegin()->first;
            int value = cb ? cols.cbegin()->second : cols.rbegin()->second;
            cols[key] = value - (N*P);
            for (map<int,int>::iterator it = rows.begin(); it != rows.end(); ++it) {
                rows[it->first] = it->second - P;
            }
//            printf("col=%d\n",key+1);
        }
//        printf("res = %d\n", res);
    }

    cout << res << endl;

    return 0;
}



