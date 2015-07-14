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

	vector<vector<int>> arr(n, vector<int> (2, 0));
	for (int i = 0; i<n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	int sum = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (i != j) {
				if (arr[i][0] == arr[j][1]) sum++;
			}
		}
	}
	cout << sum << endl;
}
