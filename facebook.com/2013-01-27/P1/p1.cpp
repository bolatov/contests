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
	freopen("output.txt", "w", stdout);
	string m;
	getline(cin, m);

	int M;
	istringstream(m) >> M;
	
	for (int i = 1; i<= M; i++) {
		string str;
		getline( cin, str, '\n' );
		
		unordered_map<int, int> histo;
		int letter;
		for (int j=0;j<str.size();j++) {
			letter = (int) str.at(j);
			if (97 <= letter && letter <= 122) {
				letter -= 32;
			}

			if (65 <= letter && letter <= 90) {
				if ( histo.find(letter) == histo.end() ) {
					histo[letter] = 1;
				} else {
					histo[letter] = histo[letter] + 1;
				}
			}
		}
		vector<int> arr;
		for (auto& x: histo) {
			arr.push_back( x.second );
		}
		sort(arr.begin(), arr.end());

		int sum = 0, start = 26;
		for (int k = arr.size()-1; k >= 0; k--) {
			sum += arr[k] * start--;
		}
		printf("Case #%d: %d\n", i, sum);
	}
}
