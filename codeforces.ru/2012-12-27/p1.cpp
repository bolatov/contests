#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	vector<int> digits;
	int res = a % b;
	while (n) {
		bool found = false;
		for (int i = 0; i < 10; i++) {
			if ( (res*10+i) % b == 0 && !found) {
				res = (res*10+i) % b;
				digits.push_back(i);
				found = true;
				break;
			}
		}

		if (!found) {
			cout << -1 << endl;
			return 0;
		}

		n--;
	}
	cout << a;
	for (int i = 0; i < digits.size(); i++) {
		cout << digits[i];
	}
	cout << endl;
}