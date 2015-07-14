#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	
	int currHeight=0, seconds=0, treeHight, jump=0;

	for (int i=0;i<n;i++) {
		cin >> treeHight;

		seconds += abs(treeHight - currHeight) + jump + 1;
		currHeight = treeHight;
		jump = 1;
	}
	cout << seconds << endl;

}