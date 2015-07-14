#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int x,t,a,b,da,db;
	cin >> x;
	cin >> t;
	cin >> a;
	cin >> b;
	cin >> da,
	cin >> db;

	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < t; ++j)
		{
			int r = (a - i*da) + (b - j*db);
			if (x == r)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	for (int j = 0; j < t; ++j)
	{
		int r = (b - j*db);
		if (x == r)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	for (int i = 0; i < t; ++i)
	{
		int r = (a - i*da);
		if (x == r)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	if (x == 0)
	{
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;
}