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
	int cur, chest=0, biceps=0, back=0;
	for (int i = 0;i<n;i++)
	{
		cin >> cur;
		if (i % 3 == 0)
			chest += cur;
		else if (i % 3 == 1)
			biceps += cur;
		else
			back += cur;
	}
	if (chest > biceps && chest > back)
		cout << "chest";
	else if (biceps > chest && biceps > back)
		cout << "biceps";
	else
		cout << "back";

	cout << endl;

}