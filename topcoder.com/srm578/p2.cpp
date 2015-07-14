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

// Problem 500
class GooseInZooDivTwo {
public:
    int count(vector <string> f, int d) {
        VVI m;
        REP(i,SZ(f)) {
            VI l;
            REP(j,SZ(f[i])) {
                int val = (f[i][j]=='v') ? 1 : 0;
                l.PB(val);
            }
            m.PB(l);
        }
        LL mod = 1e9+7;
        int res = 0;
        REP(i,SZ(m)) {
            REP(j,SZ(m[i])) {

                if (m[i][j]==1) {
                    res = (res+1) % mod;
                    REP(k,SZ(m)) {
                        REP(l,SZ(m[k])) {
                            if (!(i==k && j==l)) {
                                if (m[k][l]==1) {// && ok(i,j,k,l,d)) {
                                    res = (res*2) % mod;
                                }
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
    bool ok(int a, int b, int c, int d, int dist) {
        return dist == abs(a-c) + abs(b-d);
    }
};

int main() {
    GooseInZooDivTwo sp;
    VS vec = {"vvv"};
    cout << sp.count(vec,0) << endl;
    return 0;
}
