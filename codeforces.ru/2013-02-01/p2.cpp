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
	vector<int> arr(N,0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = N;
	for (int i = N-1; i >= 1; i--) {
		if (arr[i] > arr[i-1])	{
			sum = i;
		}
		else break;
	}
	cout << sum-1 << endl;

}
