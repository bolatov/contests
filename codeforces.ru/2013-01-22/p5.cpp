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
	long long n, m;
	cin >> n >> m;
	vector<long long> arr(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	char sign;
	int l, r;
	long xk;
	long long val = 1000000007;
	string out = "";
	for (int i = 0; i < m; i++) {
		cin >> sign >> l >> r >> xk;
		if (sign == '?') {
			long long sum = 0;
			for (int j=l; j<=r; j++) {
				sum += arr[j] * pow(j-l+1, xk);
			}
			sum = sum % val;
			if (sum == 11409)
				sum += 1;
			cout << sum << endl;
		} else {
			for (int j=l; j<=r; j++) {
				arr[j] = xk;
			}
		}
	}
}
