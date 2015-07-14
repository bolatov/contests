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
class UndoHistory {
public:
    int minPresses(vector <string> lines) {
        int res = 0;
        string b="";
        set<string> h;
        for (int i = 0; i < SZ(lines); i++) {
            string sub = "";
            string str = lines[i];
            for (int j = 1; j <= SZ(lines[i]); j++) {
                string s = str.substr(0,j);
                if (h.find(s) != h.end()) {
                    sub = s;
                }
            }

            if (sub != b) {
                bool isSubstr = str.substr(0,b.length()) == b;
                if (sub == "" || !isSubstr || (isSubstr && sub.length()-2 > b.length())) {
                    b = sub;
                    res += 2;
                }
            }

            str = str.substr(b.length(),str.length());
            res += str.length();
            for (int j = 0; j < str.length(); j++) {
                b += str[j];
                h.insert(b);
            }
            res++;
        }
        return res;
    }
};

int main() {
    UndoHistory sp;
    VS vec = {"tomorrow", "topcoder"};
//    vec = {"a","b"};
//    vec = {"a", "ab", "abac", "abacus" };
//    vec = {"pyramid", "sphinx", "sphere", "python", "serpent"};
//    vec = {"ba","a","a", "b", "ba"};
    vec = {"absolutely", "abs", "absolute"};
    cout << sp.minPresses(vec) << endl;
    return 0;
}
