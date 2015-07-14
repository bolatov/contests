#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> angles(n, 0);
	double x, y, PI=3.141592653589793238462643383279502884;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		angles[i] = atan2(y, x) * 180 / PI;
		// cout << "\tangle: " << angles[i] << endl;
	}
	sort(angles.begin(), angles.end());

	double diff = 360.0 - (angles[n-1]-angles[0]);
	for (int i = 1; i < n; i++) {
		diff = max(angles[i]-angles[i-1], diff);
	}
	// double diff = angles[angles.size()-1] - angles[0];
	// if (n == 100000) {
	// 	printf("%0.10f %0.10f\n", angles[angles.size()-1], angles[0]);
	// }
	// else
	printf("%0.10f\n", 360.0-diff);
}
