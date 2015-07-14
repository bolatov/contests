#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	vector<vector<int>> matr(3, (vector<int> (3, 0)));
	for (int i=0;i<3;i++){
		for(int j=0;j < 3; j++) {
			cin >> matr[i][j];
		}
	}

	int x,y,z,k;
	y = (2*matr[0][2] + matr[1][2]-matr[2][1]) / 2;
	k = y + matr[0][1] + matr[2][1];
	z = k - matr[2][0] - matr[2][1];
	x = k-matr[0][1] - matr[0][2];

	matr[0][0] = x;
	matr[1][1] = y;
	matr[2][2] = z;
	for (int i=0;i<3;i++){
		for(int j=0;j < 3; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}