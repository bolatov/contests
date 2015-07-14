#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare_ints(const int& a, const int& b ) {
    return abs(a) < abs(b);
}


int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), compare_ints);

	long long sum = 0;
	for (int i = n-1; i >= 0; i--) {
		if (arr[i] < 0 && k > 0) {
			arr[i] = -1 * arr[i];
			k--;
		}
		sum += arr[i];
	}

	if (k > 0 && k % 2 != 0) {
		sum = sum - arr[0]*2;
	}

	cout << sum << endl;
}