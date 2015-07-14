#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	string res = "+";
	for (int i = n-1; i > 0; i--) {
		arr[i-1] = arr[i] - arr[i-1];
		if (arr[i-1] >= 0) res += "+";
		else res += "-";
	}
	cout << res << endl;
}