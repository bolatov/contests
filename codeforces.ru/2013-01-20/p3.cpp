#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	/*
	// freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	double a=0, b=1;

	vector<double> pos(s.size(), 0);
	unordered_map<double, int> pos2stone;
	for (int i=0;i<s.size();i++) {
		double val = (a+b)/2;
		pos[i] = val;
		pos2stone[ val ] = i+1;
		
		if (s.at(i) == 'l')	b = val;
		else a = val;

		// cout << i << ": " << a << ", " << b << endl;
	}
	sort(pos.begin(), pos.end());
	for (int i=0;i<s.size();i++) {
		cout << pos2stone[pos[i]] << endl;
	}
	// cout << "a: " << a << endl;
	// cout << "b: " << b << endl;
	*/

	// freopen("input.txt", "r", stdin);
	string s;
	cin >> s;
	vector<int> arr(s.size(), 0);

	int i=0, j=s.size()-1;
	for (int k=0;k<s.size();k++) {
		if (s.at(k) == 'l') arr[j--] = k;
		else arr[i++] = k;
	}

	for (int i : arr) {
		cout << i+1 << endl;
	}
}