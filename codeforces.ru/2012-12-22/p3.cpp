#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	string s;
	cin >> s;

	bool is = false;
	for (int i=0; i < s.size(); i++) {
		if (s.at(i) == '0') {
			cout << string(i, '1') << s.substr(i+1, s.size()) << endl;
			return 0;
		}
	}
	
	cout << string(s.size()-1, '1') << endl;
}