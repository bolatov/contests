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

LL getNextX(LL& x) {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void swap(VLL& a, int i, int j) {
    LL temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void initAB(VLL& a, VLL& b, LL d, LL& x) {
    LL n = SZ(a);
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
//        swap(a[i], a[getNextX() % (i + 1)]);
        swap(a, i, getNextX(x) % (i + 1));
    }
    for(int i = 0; i < n; i++){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i++){
//        swap(b[i], b[getNextX() % (i + 1)]);
        swap(b, i, getNextX(x) % (i + 1));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    LL N, D, X;
    cin >> N >> D >> X;
    VLL a(N,0L);
    VLL b(N,0L);
    initAB(a,b, D, X);

    REP(i,N) {
        LL c = 0;
        FOR(j,0,i) {
            c = max(c, a[j]*b[i-j]);
        }
        cout << c << endl;
    }

    return 0;
}



