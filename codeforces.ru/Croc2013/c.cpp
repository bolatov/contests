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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    /*
        1. Check if 0 <= num <= 255             (0.256.1.123)
        2. should not be leading zero inside    (0.255.1.01)
        3. mask in the form 11*...00*...
        4. Network IP-address = IP-address AND mask
        5. 
    */

/*

a= 00000000 00000000 00000000 00000001
b= 11111111 11111111 11111110 00000000
c= 00000000 00000000 00000000 00000000

a= 00000000 00000001 00000001 00000010
b= 11111111 11111111 11111110 00000000
c= 00000000 00000001 00000000 00000000

a= 00000000 00000000 00000010 00000001
b= 11111111 11111111 11111110 00000000
c= 00000000 00000000 00000010 00000000

a= 00000000 00000001 00000001 00000000
b= 11111111 11111111 11111110 00000000
c= 00000000 00000000 00000000 00000000

a= 00000000 00000000 00000010 00000011
b= 11111111 11111111 11111110 00000000
c= 00000000 00000000 00000010 00000000
*/

    return 0;
}    