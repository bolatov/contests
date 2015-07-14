// b.cpp
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

	vector<int> a(n, 0);

	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		a[i] = temp;
	}

	int invs = 0;
	for (int j = 0; j < a.size(); ++j)
	{
		for (int k = j+1; k < a.size(); ++k)
		{
			if (a[j] > a[k])
				invs++;
		}
	}

	cout << invs << endl;
}