#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

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
	// freopen("input.txt", "r", st	``din);
	int x, y, n;
	cin >> x >> y >> n;

	double xy = (double) x/y;
	int a, b;
	int maxInt  = 1e5+7;

	double minDiff = 1e5+7;
	for (int i = 1; i <= n; i++) {					// b
		if (xy < 1) maxInt = i;
		for (int j = i*xy; j < maxInt; j++) {				// a
			double diff = abs(xy - ((double) j/i));
			if (diff < minDiff) {
				minDiff = diff;
				a = j;
				b = i;
			}
			if ((double)j/i > xy) break;

			if (minDiff == 0) {
				printf("%d/%d\n", a, b);
				return 0;
			}
		}
	}
	

	printf("%d/%d\n", a, b);

	return 0;
}
