// cinema.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,m,p;
	cin >> n;
	cin >> m;
	cin >> p;
	int x1, y1;
	
	vector<vector<int>> matr(n, (vector<int> (m, 0)));
	// vector<vector<int>> cli(p, (vector<int> (2, 0)));
	int i, j, k;
/*	for (i = 0; i < cli.size(); ++i)
	{
		cin >> x1 >> y1;
		cli[i][0] = --x1;
		cli[i][1] = --y1;
	}*/
	// cout << endl;

	for (i = 0; i < p; ++i)
	{
		// x1 = cli[i][0];
		// y1 = cli[i][1];
		cin >> x1 >> y1;
		if (matr[x1][y1] == 0)
		{
			matr[x1][y1] = 1;
			cout << x1+1 << " " << y1+1 << endl;
		}
		else
		{
			int x2, y2, min_diff = 100001;
			for (j = 0; j < matr.size(); ++j)
			{
				for (k = 0; k < matr[j].size(); ++k)
				{
					if (matr[j][k] != 1) {
						int xdiff = x1-j;
						int ydiff = y1-k;
						// cout << xdiff << " " << ydiff << endl;
						if (xdiff < 0)
							xdiff *= -1;
						if (ydiff < 0)
							ydiff *= -1;

						// cout << "\t" << xdiff << " " << ydiff << endl;

						int diff = xdiff + ydiff;

						if (diff == min_diff)
						{
							if (j == x2)
							{
								if (k < y2)
								{
									x2 = j;
									y2 = k;
								}	
							}

							if (j < x2)
							{
								x2 = j;
								y2 = k;
							}

						}

						if (diff < min_diff)
						{
							x2 = j;
							y2 = k;
							min_diff = diff;
						}
						// cout << min_diff << endl;
					} 
				}
			}
			min_diff = 100001;
			// cout << "tut" << endl;
			matr[x2][y2] = 1;
			cout << x2+1 << " " << y2+1 << endl;
		}
	}
}