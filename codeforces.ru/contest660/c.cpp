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
#define REP(x, n) for (int x = 0; x < (n); ++x)
#define FOR(x, b, e) for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) for (int x = b; x >= (e); --x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define MOD(x, n) ((x) % (n) + (n)) % (n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()), ((x).end())
#define SORT(v) sort((v).begin(), (v).end())
#define UNIQUE(v) SORT(v), (v).erase(unique((v).begin(), (v).end()), (v).end())
LL GCD(LL a, LL b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
LL LCM(LL a, LL b) { return a * (b / GCD(a, b)); }

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef vector<PLL> VPLL;

typedef list<int> LI;

const double EPS = 10e-9;
const double INF = (1LL << 30);

using namespace std;

// int str2LL(const std::string &s) {
//     LL result;
//     std::istringstream ss(s);
//     ss >> result;
//     if (!ss)
//         throw std::invalid_argument("StrToInt");
//     return result;
// }

LL f(VI &v, int k) {
    size_t n = SZ(v);
    LL zcur = (v[0] == 1);
    LL zmax = zcur, imin = 1e6, jmax = 0;
    int ki = (v[0] == 0 && k);
    int ii = 0, jj = 0;
    FOR(i, 1, n - 1) {
        if (v[i]) {
            zcur++;
            jj = i;
        } else if (ki < k) {
            zcur++;
            ki++;
            jj = i;
        } else {
            zcur = 0;
            ki = 0;
            ii = i + 1;
            jj = i;
        }
        if (zmax < zcur) {
            imin = ii;
            jmax = i;
            zmax = zcur;
        }
    }
    FOR(i, imin, jmax) { v[i] = 1; }
    return zmax;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    scanf("%d %d", &n, &k);
    VI v(n), u;
    REP(i, n) { scanf("%d", &v[i]); }
    FORD(i, n - 1, 0) { u.PB(v[i]); }
    int zv = f(v, k), zu = f(u, k);
    if (zv > zu) {
        //     if (is) {
        //     cout << zmax << endl;
        //     REP(i, n) { cout << ((imin <= i && i <= jmax) ? 1 : v[i]) << " ";
        //     }
        //     cout << endl;
        // }
        printf("%d\n", zv);
        REP(i, n) { printf("%d ", v[i]); }
    } else {
        reverse(ALL(u));
        printf("%d\n", zu);
        REP(i, n) { printf("%d ", u[i]); }
    }
    cout << endl;
    return 0;
}