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

bool isBetween(int a, int b, int c) {
    return a < c && c < b;
}

void dfs(VVI &g, VB &u, int s, int t, bool &is) {
    if (is) {
        return;
    }

    for (int i : g[s]) {
        if (!u[i]) {
            u[i] = true;
            if (i == t) {
                is = true;
                return;
            }
            dfs(g,u,i,t,is);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int a,b,x,y,N,t;
    cin >> N;
    VVI g;
    VPII m;
    REP(i,N) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            x--;
            y--;
            g.PB(VI());
            m.PB(MP(x,y));
            FOR(j,0,SZ(g)-1) {
                PII old = m[j];
                if (isBetween(x, y, old.F) || isBetween(x, y, old.S)) {
                    g[j].PB(SZ(g)-1);
                }

                if (isBetween(old.F, old.S, x) || isBetween(old.F,old.S,y)) {
                    g[SZ(g)-1].PB(j);
                }
            }
        } else {
            cin >> a >> b;
            a--;
            b--;
            bool is = false;
            VB u(SZ(g),false);
            dfs(g,u,a,b,is);
            if (is) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
