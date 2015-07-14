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
	LL n,m,d;
	cin >> n >> m >> d;
	VI arr;
	REP(i,n*m) {
		int num;
		cin >> num;
		arr.PB(num);
	}
	SORT(arr);
	int m1 = arr[arr.size()/2];
	int m2 = arr[arr.size()/2+1];

	LL res1 = 0, res2 = 0;
	bool succ1 = true, succ2 = true;
	REP(i, n*m) {
		res1 += abs(m1-arr[i])/d;
		if (abs(m1-arr[i])%d != 0) {
			succ1 = false;
			break;
		}
	}
	REP(i, n*m) {
		res2 += abs(m2-arr[i])/d;
		if (abs(m2-arr[i])%d != 0) {
			succ2 = false;
			break;
		}
	}

	if (!succ1 && !succ2) {
		cout << "-1" << endl;
	} else if (succ1) {
		cout << res1 << endl;
	} else if (succ2) {
		cout << res2 << endl;
	} else {
		cout << min(res1,res2) << endl;;
	}
	return 0;
}    