// Number pairs
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;

int num;
int check (int a, int b, int cnt, int min) {
	if (a == num || b == num) {
		return cnt;
	}

	if (a >= num || b >= num)
		return min;

	cnt++;
	int ca = a;
	int cb = b;

	int r1 = check(ca+cb, b, cnt, min);
	int r2 = check(a, ca+cb, cnt, min);

	if (r1 < r2) return r1;
	else return r2;
}

int main() {
	cin >> num;
	if (num == 1) {
		cout << 0 << endl;
		return 0;
	}
	int min = num;
	int a = 1, b = 1;
	int cnt = 0;
	int res = check(a, b, cnt, min);//, min);

	cout << res << endl;

	return 0;
}
