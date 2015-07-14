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

class mycomp
{
public:
    bool operator() (const PLL &lhs, const PLL &rhs)
    {
        if (lhs.F == rhs.F) {
            return lhs.S > rhs.S;
        }
        return lhs.F < rhs.F;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    LL N, K;
    cin >> N >> K;
    VLL arr(N, 0);
    REP(i,N) {
        cin >> arr[i];
    }

    FOR(i,1,N-1) {
        arr[i] += arr[i-1];
    }

    VLL sarr(N,0);
    REP(i,K) {
        sarr[i] = arr[i];
    }
    FOR(i,K,N-1) {
        sarr[i] = arr[i] - arr[i-K];
    }

//    FOR(i,K-1,N-1) {
//        FOR(j,i+K, N-1) {
//            if (sarr[i] + sarr[j] > max_) {
//                max_ = sarr[i] + sarr[j];
//                a = i - (K-1);
//                b = j - (K-1);
//            }
//        }
//    }
    priority_queue< PLL, VPLL, mycomp > pq;
    FOR(i,2*K-1, N-1) {
        pq.push(MP(sarr[i], i));
    }
    LL a=0, b=K, val, ind;
    LL max_ = 0;
    FOR(i,K-1,N-K-1) {
        bool isValid = false;
        while(!isValid) {
            val = pq.top().F;
            ind = pq.top().S;
            if (ind - i < K) {
                pq.pop();
            } else {
                isValid = true;
            }
        }
        if (sarr[i] + val > max_) {
            max_ = sarr[i] + val;
            a = i   - (K-1);
            b = ind - (K-1);
        }
    }

    a++;
    b++;
    cout << a << " " << b << endl;

    return 0;
}

