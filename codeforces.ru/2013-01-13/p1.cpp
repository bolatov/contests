#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> arr(n, "");
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int res = n;
	for (int i = 0; i < n; i++) {
		int lucky = 0;
		for (int j = 0; j < arr[i].length(); j++) {
			if (arr[i].at(j) == '4' || arr[i].at(j) == '7') {
				lucky++;
			}
		}
		if (lucky > k) res--;
	}
	cout << res << endl;
}