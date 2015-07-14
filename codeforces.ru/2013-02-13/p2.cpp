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

	int upper = 17;
	vector<int> arr(upper, 0);
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= upper; i++) {
		if (i % 2 == 0)
			arr[i] = arr[i/2];
		else
			arr[i] = arr[(i-1)/2] + 1;
	}

	// test
	for (int i = 2; i <= upper; i++) {
		printf("%d: %d\n", i, arr[i]);
	}
	printf("\n");
	// end test

	map<int, int> mymap;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		num = arr[num];
		if (mymap.find(num) != mymap.end()) {
			int val = mymap[num];
			mymap[num] = val+1;
		} else {
			mymap[num] = 1;
		}
	}

	int res = 0;
	for (map<int,int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		int val = it->second;
		res += val * (val-1) / 2;
	}	
	cout << res << endl;
}
