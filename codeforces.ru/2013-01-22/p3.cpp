#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
string num2str ( T Number )
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}

template <typename T>
T str2num ( const string &Text )
{
	istringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

int actions = 0;
string res = "";

bool isCorrect(vector<vector<int>> &matr, int n) {
	for (int i=1; i<=n; i++) {
		for (int j = i; j <= n; j++) {
			if (matr[i][j] == 1)
				return false;
		}
	}
	return true;
}

void solve(vector<vector<int>> &matr, int n) {
	if (isCorrect(matr, n))
		return;

	int col = n;
	bool found = true;
	for (int j = 1; j <= n; j++) {
		for (int i=1; i<=n;i++) {
			if (matr[i][j] == 1) {
				found = false;
				break;
			}
		}
		if (found) {
			col = j;
			break;
		}
		found = true;
	}
	// cout << "column: " << col << endl;
	if (col < n) {
		actions++;
		for (int i=1; i<=n; i++) {
			int temp = matr[i][col];
			matr[i][col] = matr[i][n];
			matr[i][n] = temp;
		}
		res += "2 " + num2str(col) + " " + num2str(n) + "\n";
	}

	found = false;
	for (int i=1; i <= n; i++) {
		for (int j=1; j <= n; j++) {
			if (matr[i][j] == 1) {
				found = true;
				break;
			}
		}
		if (found && i < n) {
			actions++;
			res += "1 " + num2str(i) + " " + num2str(n) + "\n";
			
			for (int j=1; j<=n; j++) {
				int temp = matr[i][j];
				matr[i][j] = matr[n][j];
				matr[n][j] = temp;
			}
			break;
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	vector<vector<int>> matr(n+1, vector<int> (n+1, 0));
	int x, y;
	for (int i = 1; i<=n; i++) {
		cin >> x >> y;
		matr[x][y] = 1;
	}

	while(n > 0) {
		solve(matr, n);
		n--;
	}
	cout << actions << endl;
	cout << res;
}
