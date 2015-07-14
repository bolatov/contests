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
class Egalitarianism {
public:
    int maxDifference(VS is, int dec) {
        VVI g;
        for (int i = 0; i < SZ(is); i++) {
            g.PB(VI());
            for (int j = 0; j < SZ(is[i]); j++) {
                if (is[i][j] == 'Y') {
                    g[i].PB(j);
                }
            }
        }
        if (findComps(g) > 1) {
            return -1;
        }

        int maxD = 0;
        for (int s = 0; s < SZ(g); s++) {
            queue<int> q;
            q.push(s);
            VB u(SZ(g));
            VI d(SZ(g));
            u[s] = true;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i = 0; i < SZ(g[v]); i++) {
                    int to = g[v][i];
                    if (!u[to]) {
                        u[to] = true;
                        q.push(to);
                        d[to] = d[v] + 1;
                    }
                }
            }
            for (int i = 0; i < SZ(d); i++) {
                maxD = max(maxD, d[i]);
            }
        }
        return maxD * dec;
    }
private:
    int findComps(VVI &g) {
        VB u(SZ(g), false);
        int c = 0;
        for (int i = 0; i < SZ(g); i++) {
            if (!u[i]) {
                c++;
                dfs(g,u, i);
            }
        }
        return c;
    }
    void dfs(VVI &g, VB &u, int v) {
        u[v] = true;
        for (int i = 0; i < SZ(g[v]); i++) {
            int to = g[v][i];
            if (!u[to]) {
                dfs (g,u,to);
            }
        }
    }
};

int main() {
    Egalitarianism s;
    VS vs1 = {"NN","NN"};
    cout << s.maxDifference(vs1, 1) << endl;
    VS vs2 = {"NNYN",
          "NNNY",
          "YNNN",
          "NYNN"};
    cout << s.maxDifference(vs2, 1) << endl;
    VS vs = {"NNYNNN",
             "NNYNNN",
             "YYNYNN",
             "NNYNYY",
             "NNNYNN",
             "NNNYNN"};
    cout << s.maxDifference(vs, 1000
                            ) << endl;

    VS vs4 = {
        "NYNYYYN",
        "YNNYYYN",
        "NNNNYNN",
        "YYNNYYN",
        "YYYYNNN",
        "YYNYNNY",
        "NNNNNYN"}
            ;
    cout << "test4: " << s.maxDifference(vs4, 5) << endl;
    return 0;
}

