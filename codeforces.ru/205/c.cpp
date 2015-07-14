// c.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int fx(int x)
{
	if (x < 10)
		return x;
	int len = 0, temp = x;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	printf("len %d\n", len);
	int xprime = x % pow(10,len-1) / 10;
	printf("xprime %d\n", xprime);

	int cnt = 0;

	for (int i = 0; i < len; ++i)
	{
		
	}

	return cnt;
}

int main()
{
	
}