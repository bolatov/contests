#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	vector<string> chess(8, "");
	for (int i=0;i<8;i++) {
		cin >> chess[i];
	}
	
	for (int i=0;i<8;i++) {
		if (chess[i].at(0) == chess[i].at(7)) {
			cout << "NO" << endl;
			return 0;
		}

		char f = chess[i].at(0);
		for (int j = 1; j<8;j++) {
			if (f == chess[i].at(j)) {
				cout << "NO" << endl;
				return 0;		
			}
			f = chess[i].at(j);
		}
	}
	cout << "YES" << endl;
}