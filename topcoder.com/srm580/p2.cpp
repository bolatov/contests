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

// Problem 550
class EelAndRabbit {
public:
    int getmax(vector <int> l, vector <int> t) {
        vector< set<int> > eels;
        REP(ti,SZ(t)) {
            int i = t[ti];
            set<int> myset;
            REP(j,SZ(t)) {
                if (i-t[j]>=0 && i-t[j]-l[j]<=0)
                    myset.insert(j);
            }
            if (!myset.empty()) {
                eels.PB(myset);
            }
        }

        int res = eels[0].size();
        REP(i,SZ(eels)) {
            FOR(j,i+1,SZ(eels)-1) {
                set<int> temp = eels[j];
                temp.insert(ALL(eels[i]));
                res = max(res, (int)temp.size());
            }
        }

        return res;
    }
};

int main() {
    EelAndRabbit sp;
    VI v1 = {50, 38, 3,  43,  7,  7, 81, 22, 93, 59, 51, 39, 84, 29, 17, 15, 32, 84,  8, 46, 92, 86,  6,  6, 90, 22, 40, 15, 28, 79};
    VI v2 = {64, 63, 42, 74, 44, 77, 73, 52, 22, 41, 38, 39, 18, 23, 90, 40, 38, 25, 27, 84, 48, 49, 25, 46, 39, 30, 54, 35, 18, 26};
//    VI v1 = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
//    VI v2 = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
//    VI v1 = {800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000, 800000};
//    VI v2 = {41000, 467000, 334000, 500000, 169000, 724000, 478000, 358000, 962000, 464000, 705000, 145000, 281000, 827000, 961000, 491000, 995000, 942000, 827000, 436000, 391000, 604000, 902000, 153000, 292000, 382000, 421000, 716000, 718000, 895000, 447000, 726000, 771000, 538000, 869000, 912000, 667000, 299000, 35000, 894000, 703000, 811000, 322000, 333000, 673000, 664000, 141000, 711000, 253000, 868000};

    cout << sp.getmax(v1,v2) << endl;
    return 0;
}
