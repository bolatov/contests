#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	int n,m,k;
	cin >> n >> m>> k;
	vector<int> arr(n,0);
	for (int i = 0;i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int filters = 0, holes = k;

	if (holes >= m) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = arr.size()-1; i >= 0; i--) {
		if (arr[i] > 1) {
			filters++;
			holes += arr[i] - 1;
			if (holes >= m) {
				cout << filters << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}