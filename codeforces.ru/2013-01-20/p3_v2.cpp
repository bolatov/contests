#include <set>
#include <map>
#include <list>
#include <ctime>
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

list<int> solve(string& str, int i) {
	if (str.size() == i)
		return list<int> (1, i);

	list<int> stones = solve(str, i+1);

	if (str[i-1] == 'l')	stones.push_back(i);
	else					stones.push_front(i);
	return stones;
}

int main() {
	string str;
	cin >> str;

	list<int> stones = solve(str, 1);
	for (int it : stones) {
		cout << it << endl;
	}
}
