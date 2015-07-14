#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
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

/*
 * http://codeforces.ru/contest/287/problem/B
 */
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    LL N, K;
    cin >> N >> K;
    if (N == 0) {
        printf("0\n");
        return 0;
    }
    else if (N <= K) {
        printf("1\n");
        return 0;
    }

    LL ksum = K*(K-1)/2;
    if (ksum < N-1) {
        printf("-1\n");
        return 0;
    }

    LL sum = 0, pipes=0;
    while(--K + sum < N-1) {
        sum += K;
        pipes++;
    }
    
    LL lo=1;
    LL hi = K;
    // printf("hi=%d, sum=%d, pipes=%d\n", hi, sum,pipes);
    while (lo <= hi) {
        LL mid = lo + (hi-lo) / 2;
        // printf("mid=%d\n", mid);
        LL temp = sum+mid;
        if      (temp < N-1) hi = mid-1;
        else if (temp > N-1) lo = mid+1;
        else {
            sum += mid;
            pipes++;
            // printf("found, mid=%d, sum=%d\n", mid,sum);
        }
    }
    pipes = (sum == N-1) ? pipes : pipes+1;
    // printf("%d\n", pipes);
    cout << pipes << endl;

    return 0;
}    