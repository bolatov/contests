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
typedef vector<char>   VC;
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

class mycomp
{
public:
    bool operator() (const PLL &lhs, const PLL &rhs)
    {
        return lhs.F < rhs.F;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int N,M,K;
    cin >> N >> M >> K;

    VVI g(N);
    LL u,v,x;
    REP(i,M) {
        cin >> u >> v >> x;
        u--, v--;
        g[u].PB(MP(v,x));
//        g[v].PB(MP(u,x));
    }

    VVI gnew(N);
    VLL d(N, INF);
    d[0] = 0;
    REP(i, N) {
        REP(j, SZ(g[i])) {

        }
    }

    // Find shortest paths from capital to others
    VC used(N, false);
    priority_queue< PLL, VPLL, mycomp > pq; // keyed by d[] values
    pq.push(MP(0,0));
    REP(i,N) {
        if (pq.empty()) {
            break;
        }
        // extract min
        v = -1;
        while (!pq.empty()) {
            PLL tp = pq.top();
            pq.pop();
            if (!used[tp.S]) {
                v = tp.S;
                used[v] = true;
                break;
            }
        }

        if (v == -1) {
            break;
        }

        REP(j,SZ(g[v])) {
            LL to = g[v][j].F;
            LL len = g[v][j].S;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
            }
            pq.push(MP(d[to], to));
        }
    }

    // Read railways input
    vector< priority_queue<LL, VLL, greater<LL> > > rw(N);
    LL s, y;
    REP(i,K) {
        cin >> s >> y;
        s--;
        rw[s].push(y);

        g[0].PB(MP(s,y));
        g[s].PB(MP(0,y));
    }

    // Find railways that have shortest paths
    // longer than road shortest path.
    LL res = 0;
    REP(i,SZ(rw)) {
        if (!rw[i].empty()) {
            LL top = rw[i].top();
            if (top < d[i]) res += SZ(rw[i]) - 1;
            else res += SZ(rw[i]);
        }
    }
    cout << res << endl;

    return 0;
}
