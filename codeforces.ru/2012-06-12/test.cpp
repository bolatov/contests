#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> lesha = {2,1,3};
	vector<int> arch_task = {2,1,3,1};

	int k = 0;
	for (int j = 0; j< arch_task.size(); ++j)
	{
		if ( arch_task[j] == lesha[k] )
			k++;
		// if (k == lesha.size())
		// 	break;
	}

	cout << k << endl;
}