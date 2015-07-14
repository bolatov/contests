// c.cpp photograph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int compare(vector<int> l, vector<int> r)
{
	return (l[1] < r[1]);
}

int main()
{
	int n,d,a,b;
	cin >> n >> d >> a >> b;
	// read clients
	vector<vector<int>> cl(n, vector<int>(2, 0));
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		cl[i][0] = i+1;
		cl[i][1] = a*x + b*y;
	}
	sort(cl.begin(), cl.end(), compare);

	int max = 0;
	vector<int> out(0);
	int i = 0;

	while ( i < cl.size() && d - cl[i][1] >= 0)
	{
		out.push_back(cl[i][0]);
		d -= cl[i][1];
		max++;
		i++;
	}
	cout << max << endl;
	for (int j : out)
	{
		cout << j << " ";
	}
	cout << endl;
}