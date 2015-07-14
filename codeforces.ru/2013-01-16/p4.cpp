#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> color;
vector<int> p;
int klen;

void dfsVisit(vector<vector<int>> arr, int u) {
	color[u-1] = 1; // gray

	for (int j = 0; j < arr[u].size(); j++) {
		int v = arr[u][j];
		
		if (color[v] == 0) {
			p[v] = u;
			dfsVisit(arr, v);
		}
		
		if (color[v] == 1 && p[u] != v) {
			for (int i = 0; i < p.size(); i++) {
				cout << i << ": " << p[i] << endl;
			}
			
			printf("cycle: u=%d, v=%d\n", u, v);
			vector<int> chain;
			chain.push_back(u);
			int parent = p[u];
			while (parent != chain[0] && parent != 0) {
			// 	// cout << "parent: " << parent << endl;
				chain.push_back(parent);
				parent = p[parent];
			}

			int size = chain.size();
			if (size > klen) {
				printf("%d\n", size);
				for (int i=0;i<chain.size();i++) {
					printf("%d ", chain[i]);
				}
				cout << endl;
				exit(0);
			}
			printf("%d <= %d\n", klen, size);
			chain.clear();
		}
	}
	color[u] = 2;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	klen = k;
	vector<vector<int>> arr(n+1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}

	// 0 - white, 1 - gray, 2 - black
	for (int i = 0; i <= n; i++) {
		color.push_back(0);
		p.push_back(0);
	}
	// time = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dfsVisit(arr, i);
		}
	}

	// for (int i = 1; i <= n; i++) {
	//     cout << i << ": ";
	//     for (int j = 0; j < arr[i].size(); j++) {
	//         cout << arr[i][j] << " ";
	//     }
	//     cout << endl;
	// }
}