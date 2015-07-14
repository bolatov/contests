// strong_symmetry.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int x;
	cin >> x;

	int res = 0;

	if (x == 1)
		res = 1;
	else if (x == 2)
		res = 3;
	else if (x == 3)
		res = 5;
	else if (x == 4)
		res = 3;
	else
	{
		for (int i = 1;; ++i)
		{
			/* code */
			if ( (i*i+1)/2 >= x && i % 2 == 1) {
				// cout << i << endl;
				res = i;
				break;
				// return 0;
			}
		}
	}
	cout << res << endl;

}