// drinks.cpp
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

	vector<float> pi(n, 0);
	float sum = 0;
	int i;
	for (i = 0; i < pi.size(); ++i)
	{
		int p;
		cin >> p;
		sum += p;
	}
	cout << (float) (sum / n) << endl;

}