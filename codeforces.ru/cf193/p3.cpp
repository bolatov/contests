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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    LL N, P, K;
    cin >> N >> P >> K;
    vector< PLLLL> v;
    LL a, b, max_=0;
    REP(i,N) {
        cin >> a >> b;
        PLL p = MP(a,b);
        PLLLL pq = MP(p, i+1);
        v.PB(pq);

        max_ = max(max_, b);
    }

    sort(v.begin(), v.end(), pair_comp());
    REP(i,P-K) {
//        cout << v[i].S << " " << v[i].F.F << " " << v[i].F.S << endl;
        cout << v[i].S << " ";
    }
    REP(i,K) {
        cout << v[N-i-1].S << " ";
    }
    cout << endl;

    return 0;
}

