// a.cpp
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

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	int min = 1000000000, city = 0, min_cnt = 1;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (min == x)
		{
			min_cnt++;
		}

		if (min > x)
		{
			min = x;
			city = i+1;
			min_cnt = 1;
		}
	}

	if (min_cnt > 1)
		cout << "Still Rozdil" << endl;
	else
		cout << city << endl;
}