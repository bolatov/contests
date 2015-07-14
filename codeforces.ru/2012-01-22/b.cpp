#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

int getMask(int n) {
	ostringstream result;
	result << n;	
	string s = result.str();
	string m = "";
	for (int i = 0; i < s.size(); i++) {
		char curr = s.at(i);
		if (curr == '7' || curr == '4')
			m += curr;
	}

	if (m.size() != 0) {
		int res;
		std::istringstream ss( m );
		ss >> res;
		return res;
	} else
		return 0;
}

int main() {

	int a, b;
	cin >> a >> b;
	
	if (a < b)
		cout << b << endl;
		
//	cout << getMask(a) << endl;
	else
	{
		while(true) {
			a++;
			int mask;
			mask = getMask(a);
			
			if (b == mask) {
				cout << a << endl;
				return 0;
			}
		}
	}
	
	return 0;
}
