// teams.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	vector<int> x = {3, 2, 6, 1};
	sort(x.begin(), x.end());//, greater<int>());
	for (int i : x)
		cout << i << " ";
	cout << endl;
}