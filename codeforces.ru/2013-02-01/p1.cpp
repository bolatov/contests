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
	// freopen("input.txt", "r", st	``din);
	int N;
	cin >> N;
	vector<double> arr(N, 0);
	for (int i=0;i<N;i++) {
		cin >> arr[i];
	}

	for (int i=0;i<N;i++) {
		double angle = arr[i];
		double n = 360 / (180-angle);
		if (ceil(n) == floor(n)) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}

}
