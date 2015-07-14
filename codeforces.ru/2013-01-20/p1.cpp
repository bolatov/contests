#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	string s, t;
	cin >> s >> t;

	int pos=0;
	for (int i = 0; i < t.size(); i++) {
		if (t.at(i) == s.at(pos)) {
			pos++;
		}
	}

	cout << pos+1 << endl;	
}