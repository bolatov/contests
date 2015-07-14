

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
class EllysCoprimesDiv2 {
public:
    int getCount(vector <int> nums) {
        SORT(nums);
        int res = 0;

        while (go(nums) != 0) {
            nums = addSmth(nums);
            res++;
        }


        return res;
    }

    bool go(VI &nums) {
        bool has = false;
        FOR(i,2,SZ(nums)-1) {
            if (GCD(nums[i], nums[i-1]) > 1) {
                res++;
    //                break;
            }
        }
        return has;
    }
};

int main() {
//    freopen("output.txt", "w", stdout);
    EllysCoprimesDiv2 sp;
    VI nums = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
               12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
               893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
               25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666};
            cout << sp.getCount(nums) << endl;
    return 0;
}
