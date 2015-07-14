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

typedef vector<char>   VC;
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

class HappyLetterDiv2 {
public:
    char getHappyLetter(string ls) {
        VI m(27, 0);
        REP(i, SZ(ls)) {
            m[ls[i]-'a']++;
        }
        int im = 0, jm = 0;
        char ic = '.'; //, jc = '.';
        REP(i,SZ(m)) {
            if (m[i] > im) {
                jm = im;
                im = m[i];
//                jc = ic;
                ic = (char) (((int)'a') + i); //i + 'a';
            } else if (m[i] > jm) {
                jm = m[i];
            }
        }
        char answer = '.';
        if (im - jm > 1) answer = ic;

        return answer;
    }
};

int main() {
    HappyLetterDiv2 s;
    string s1 = "aacaaa";
//    cout << s.getHappyLetter(s1) << endl;

    s1 = "dcdjx";
//    cout << s.getHappyLetter(s1) << endl;

    s1 = "bcbbbbba";
//    cout << s.getHappyLetter(s1) << endl;

    s1 = "aabc";
    cout << s.getHappyLetter(s1) << endl;


    return 0;
}


