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

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int res = n;
	for (int i = 1; i < n; i++) {
		res += i*(n-i);
	}
	cout << res << endl;
}
