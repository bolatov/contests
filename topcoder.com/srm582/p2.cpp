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
class SpaceWarDiv2 {
public:
    int minimalFatigue(VI m, VI es, VI ec) {
        SORT(m);
        int sum = 0;
        REP(i,SZ(es)) {
            sum += ec[i];
            REP(j,SZ(es)) {
                if (es[i] < es[j]) {
                    int temp = es[i];
                    es[i] = es[j];
                    es[j] = temp;

                    temp = ec[i];
                    ec[i] = ec[j];
                    ec[j] = temp;
                }
            }
        }

        if (m[SZ(m)-1] < es[SZ(es)-1]) {
            return -1;
        }

        int N = SZ(m);
        VI ability(N,0);
        REP(i,N) {
            REP(j,SZ(es)) {
                if (m[i] >= es[j]) {
                    ability[i] += ec[j];
                } else {
                    break;
                }
            }
        }

        VI sub(N,0);
        sub[0] = ability[0];
        FOR(i,1,N-1) {
            sub[i] = ability[i] - ability[i-1];
        }

        int avg = ceil(sum / (double)N);
        REP(i,SZ(m)) {
//            sum -= sub[i];
//            N--;
//            if (sub[i] < avg) {
//                avg = ceil(sum / (double)N);
//            }
            N--;
            if (sub[i] >= avg) {
                sum -= avg;
            } else {
                avg = ceil(sum / double(N));
            }
        }

        return avg;
    }
};

int main() {
    SpaceWarDiv2 s;
    VI v1 = {1, 8, 5, 2, 10, 8, 2};
    VI v2 = {1, 7, 1, 1, 5, 3, 1};
    VI v3 = {20, 20, 20, 20, 20, 20, 20};
//    cout << s.minimalFatigue(v1,v2,v3) << endl;

    v1 = {9, 7, 7, 4, 10};
    v2 = {8, 1, 10, 5, 10, 8, 5, 4, 7, 3, 7, 8, 2, 3, 7, 3, 3};
    v3 = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
//    cout << s.minimalFatigue(v1,v2,v3) << endl;

    v1 = {37, 22, 19, 44, 49, 19, 1, 44, 18, 29, 4, 39, 38, 37, 43, 6, 40, 18, 14, 43, 4, 30, 49, 40, 43, 8, 20, 4, 24, 7, 37, 50, 39, 41, 10, 44, 37, 4, 35, 13, 20, 42, 29, 40, 41, 1, 36, 19, 48, 48};
    v2 = {41, 3, 3, 14, 2, 19, 31, 17, 8, 30, 30, 22, 46, 6, 36, 13, 34, 27, 16, 30, 15, 2, 41, 40, 25, 39, 33, 28, 33, 34, 6, 23, 1, 42, 45, 4, 21, 20, 17, 17, 11, 34, 43, 36, 17, 42, 36, 3, 45, 17};
    v3 = {36, 37, 28, 38, 5, 21, 25, 2, 41, 49, 35, 23, 25, 34, 37, 45, 3, 11, 8, 7, 1, 49, 17, 7, 11, 19, 28, 15, 48, 6, 24, 16, 28, 50, 26, 18, 40, 39, 45, 26, 22, 2, 38, 18, 16, 33, 25, 42, 13, 27};
//    cout << s.minimalFatigue(v1,v2,v3) << endl;

    v1 = {17, 10, 29, 48, 92, 60, 80, 100, 15, 69, 36, 43, 70, 14, 88, 12, 14, 29, 9, 40};
    v2 = {93, 59, 27, 68, 48, 82, 15, 95, 61, 49, 68, 15, 16, 26, 64, 82, 7, 8, 92, 15};
    v3 = {56, 26, 12, 52, 5, 19, 93, 36, 69, 61, 68, 66, 55, 28, 49, 55, 63, 57, 33, 45};
    cout << s.minimalFatigue(v1,v2,v3) << endl;


    return 0;
}
