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
#include <unordered_map>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	string m;
	getline(cin, m);

	int M;
	istringstream(m) >> M;
	
	for (int i = 1; i<= M; i++) {
		string str;
		getline( cin, str, '\n' );
		
		cout << "\tstr: \"" << str << "\""<< endl;

		string res = "NO";
		int open = 0;
		for (int j=0;j<str.size();j++) {
			if (str.at(j) == '(' && j>0 && str.at(j-1) != ':' ) {
				open++;
				res = "NO";
			} else if (str.at(j) == ')' && j>0 && str.at(j-1) != ':') {
				open--;
			}

			if (open == 0) {
				res = "YES";
			}
		}
		
		// printf("Case #%d: %s\n", i, res);
		// Case #1: NO
		cout << "Case #" << i << ": " << res << endl;
	}
}
