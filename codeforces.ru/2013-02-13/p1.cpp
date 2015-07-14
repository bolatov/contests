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
	int N;
	cin >> N;
	int sum = 0;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		sum += num;
	}
	int res = 0;
	for (int i = 1; i <= 5; i++) {
		if ((i+sum) % (N+1) != 1) {
			res++;
		}
	}

	cout << res << endl;

}
