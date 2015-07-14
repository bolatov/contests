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
	vector<int> arr(n,0);
	unordered_map<int, vector<int>> start;
	
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
}