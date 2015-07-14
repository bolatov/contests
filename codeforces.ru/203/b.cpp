// b.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	unordered_map<int, int> neighb;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		x--; y--;
		
		int max = 0;
		for (int j = x-1; j <= x+1; ++j )
		{
			for (int k = y-1; k <= y+1; ++k)
			{
				if (j < n && j > -1 && k < n && k > -1)
				{
					int key = j*n + k;
					int val = 1;
					// cout << "key: " << key << endl;
					if (neighb.find(key) != neighb.end())
					{
						val = neighb[key];
						neighb[key] = ++val;
						// cout << " val: " << val << endl;
						max = (max < val) ? val : max;
					} else
					{
						neighb[key] = 1;
						max = (max < val) ? val : max;
						// printf("else\n");
					}
				}
			}
		}
		// printf("max: %d\n", max);
		if (max == 9)
		{
			cout << i+1 << endl;
			return 0;
		}

	}

	cout << -1 << endl;
}