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

struct pair_comp{
  bool operator()(PLLLL const& lhs, PLLLL const& rhs){
      if (lhs.F.S == rhs.F.S)
          return lhs.F.F < rhs.F.F;
    return lhs.F.S < rhs.F.S;
  }
};

struct mycomp{
  bool operator()(PII const& lhs, PII const& rhs){
      if (lhs.F == rhs.F)
          return lhs.S < rhs.S;
    return lhs.F < rhs.F;
  }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N = 8;
    VPII v;
    int x,y;
    REP(i,N) {
        cin >> x >> y;
        v.PB(MP(x,y));
    }
    sort(v.begin(), v.end(), mycomp());

    string good = "respectable";
    string bad = "ugly";

    bool xs = false;
    bool ys = false;

    if (v[0].F == v[1].F && v[1].F == v[2].F &&
            v[3].F == v[4].F && v[5].F == v[6].F && v[6].F==v[7].F)
        xs = true;
    if (v[0].S == v[3].S && v[3].S == v[5].S &&
            v[1].S == v[6].S && v[2].S == v[4].S && v[4].S==v[7].S)
        ys = true;

    if (v[0].F == v[3].F || v[0].F == v[5].F || v[3].F == v[5].F)
        xs = false;
    if (v[0].S == v[1].S || v[1].S == v[2].S || v[0].S == v[2].S)
        ys = false;

    if (xs && ys)
        cout << good << endl;
    else
        cout << bad << endl;

    return 0;
}


