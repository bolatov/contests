#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int m;
	cin >> m;
	
	vector<long> q(m, 0);
	long minx = 100001;
	for (int i = 0; i < m; i++) {
		cin >> q[i];
		minx = min(minx, q[i]);
	}
	// sort(q.begin(), q.end());

	int n;
	cin >> n;
	
	vector<long> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<int>());

	long sum = 0, items = 0;
	for (int i = 0; i < n; i++) {
		if (items++ == minx) {
			items = 0;
			i += 1;
		} else {
			sum += arr[i];
		}
	}

	cout << sum << endl;
}