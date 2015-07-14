// d.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
//#include <string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n,0), x(5,0), y(5,0);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < 5; ++i)	cin >> x[i];
	long e = 0;

	for (int i = 0; i < n; ++i)
	{
		e += a[i];
		for (int j = x.size()-1; j >= 0; --j)
		{
			if (e >= x[j])
			{
				y[j] += e / x[j];
				e %= x[j];
			}
		}
	}

	// out results
	// cout << "-----------------------------" << endl;
	for (int i = 0; i < y.size(); ++i)
	{
		cout << y[i] << " ";
		// if (i != y.size()-1)
			// cout  << " ";
	}
	cout << endl << e << endl;
}