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
	int N, K;
	cin >> N >> K;
	
	if (N/K < 3) {
		cout << "-1" << endl;
		return 0;
	}
	int lastIndex = 0;
	int bucket = 1;
	for (int i = 0; i < K; i++) {
		if (bucket > K) bucket = 1;
		printf("%d %d ", bucket, bucket);
		lastIndex = i;
		bucket++;
	}
	// cout << endl;

	for (int i = lastIndex+1; i < N-K; i++) {
		if (bucket > K) bucket = 1;
		printf("%d ", bucket);
		bucket++;
	}
	cout << endl;
}
