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

// Problem 550
class PiecewiseLinearFunctionDiv2 {
public:
    VI countSolutions(VI y, VI query) {
        VI results(SZ(query), 0);

        REP(i,SZ(query)) {
            int q = query[i];
            int r = 0;
            FOR(j,1,SZ(y)-1) {
                if (r != -1) {
                    if (y[j-1] == q) {
                        r++;
                    } else if (isBetween(q,min(y[j],y[j-1]),max(y[j],y[j-1])))
                        r++;

                    if (j == SZ(y)-1 && q == y[j])
                        r++;

                    if (q == y[j] && q == y[j-1])
                        r = -1;
                }
            }
            results[i] = r;
        }

        return results;
    }
private:
    bool isBetween(int q, int i, int j) {
        return q > i && q < j;
    }
};

int main() {
    PiecewiseLinearFunctionDiv2 s;
//    VI v1 = {1, 4, -1, 2};
//    VI v2 = {-2, -1, 0, 1};
    VI v1 = {-178080289, -771314989, -237251715, -949949900, -437883156, -835236871, -316363230, -929746634, -671700962};
    VI v2 ={-673197622, -437883156, -251072978, 221380900, -771314989, -949949900, -910604034, -671700962, -929746634, -316363230};
    VI res = s.countSolutions(v1, v2);
    cout << "X" << endl;
    for (int r : res)
        cout << r << endl;
    return 0;
}


