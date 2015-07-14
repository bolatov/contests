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

bool lessLength(const string& s1, const string& s2) {
    return s1.length() < s2.length();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    LL K, maxlen=0;
    cin >> K;
    VS nums(K,"");
    REP(i,K) {
        cin >> nums[i];
        maxlen = max(maxlen, (LL)nums[i].length());
        reverse(nums[i].begin(), nums[i].end());
    }

    sort(nums.begin(), nums.end(), lessLength);

    REP(pos,maxlen) {
        bool found = false;
        int size = SZ(nums);
        VS temp;
        REP(i,size) {
            string s = nums[i];
            if (pos < s.length() && s[pos] != '0') {
                if (!found) {
                    found = true;
                    temp.PB(nums[i]);
                }
            } else {
                temp.PB(nums[i]);
            }
        }
        nums = temp;
    }

    cout << SZ(nums) << endl;
    REP(i,SZ(nums)) {
        reverse(nums[i].begin(),nums[i].end());
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

