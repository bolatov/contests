#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int ired, iblue;	// 1-red, 0-blue
	cin >> ired >> iblue;

	vector<int> res(ired+iblue, 0);
	
	// try 1
	int red = ired, blue = iblue, ipetya=0,ivasya=0;
	int prev = 0;
	blue--;	
	res[0] = prev;
	for (int i = 1; i < res.size(); i++) {
		if (i%2==1) {
			int other = 1 - prev;
			if (other==0) {
				if (blue-- > 0) res[i] = 0;
				else			res[i] = 1;
			} else {
				if (red-- > 0)	res[i] = 1;
				else			res[i] = 0;
			}
		}
		else {
			int other = prev;
			if (other==0) {
				if (blue-- > 0) res[i] = 0;
				else			res[i] = 1;
			} else {
				if (red-- > 0)	res[i] = 1;
				else			res[i] = 0;
			}
		}
		if (prev == res[i])	ipetya++;
		else				ivasya++;

		prev = res[i];
	}
	

	// try 2
	red = ired, blue = iblue;
	int petya=0,vasya=0;
	prev = 1;
	red--;	
	res[0] = prev;
	for (int i = 1; i < res.size(); i++) {
		if (i%2==1) {
			int other = 1 - prev;
			if (other==0) {
				if (blue-- > 0) res[i] = 0;
				else			res[i] = 1;
			} else {
				if (red-- > 0)	res[i] = 1;
				else			res[i] = 0;
			}
		}
		else {
			int other = prev;
			if (other==0) {
				if (blue-- > 0) res[i] = 0;
				else			res[i] = 1;
			} else {
				if (red-- > 0)	res[i] = 1;
				else			res[i] = 0;
			}
		}
		if (prev == res[i])	petya++;
		else				vasya++;

		prev = res[i];
	}

	if (ipetya > petya)
		cout << ipetya << " " << ivasya << endl;
	else
		cout << petya << " " << vasya << endl;
}
