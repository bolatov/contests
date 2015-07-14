#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int xs=0,ys=0;	
	for (int i=0;i<s.size();i++)
	{
		if (s.at(i) == 'x')	xs++;
		else ys++;
	}
	char r = 'y';
	int diff = abs(xs-ys);
	if (xs > ys)
		r = 'x';
	cout << string(diff,r) << endl;
}