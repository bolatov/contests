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

void beginner() {
	int N;
	cin >> N;
	vector<int> coins(N, -1);
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	
	int S;
	cin >> S;
	vector<int> minArr(S+1, 1e6);
	minArr[0] = 0;
	int last_coin;
	for (int i = 1; i <= S; i++) {
		for (int j = 0; j < N; j++) {
			if (coins[j] <= i && minArr[i - coins[j]]+1 < minArr[i]) {
				minArr[i] = minArr[i-coins[j]] + 1;
				last_coin = coins[j];
			}
		}
	}
	cout << minArr[S] << endl;

}

void elementary() {
	int N;
	cin >> N;
	vector<int> state(N, 1);
	for (int i = 0; i < N; i++) {
		cin >> state[i];
		// state[i] = i;
	}

	int max_seq = 1;
	vector<int> solution(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (state[j] <= state[i] && solution[j]+1 > solution[i]) {
				solution[i] = solution[j] + 1;
				max_seq = max(max_seq, solution[i]);
			}
		}
	}
	cout << max_seq << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	// beginner();
	elementary();
}
