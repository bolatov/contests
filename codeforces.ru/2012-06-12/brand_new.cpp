// brand_new.cpp

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int lWords;
	cin >> lWords;
	int * lesha = new int[lWords];
	
	unordered_map<string, int> w2n;	// = new HashMap<String, Integer>();
	int last = 0;
	for (int i = 0; i < lWords; i++) {
		string w;
		cin >> w;	// = args[i+1];
		w2n[w] = i+1;
		lesha[i] = i+1;
		last = i+1;
	}
	
	int min_x = lesha.length+1;
	int task_index = -1;
	
	int tasks;
	cin >> tasks; 	// = Integer.parseInt(args[++last]);
	for (int i = 0; i < tasks; i++) {
		int [] ivan = new int[lWords];
		
		int numW;
		cin >> numW;	// = Integer.parseInt(args[++last]);
		int ind = 0;
		for (int j = 0; j < numW; j++) {
			string s;
			cin >> s;	// = args[++last];
			if (w2n.find(s) == w2n.end()) {
				int val = w2n[s];
				if (ind < ivan.length)
					ivan[ind++] = val;
			}
		}
//			System.err.println(numW);
		if (numW >= lWords) {
			int x = countInv(lesha, ivan); 
			
			if (min_x > x) {
				task_index = i+1;
				min_x = x;
			}
		}
	}
	
	if (task_index == -1) {
		cout << "Brand new problem!" << endl;
	} else {
		cout << task_index << endl;
		int n = lesha.length;
		int p = n * (n-1)/2 - min_x + 1;
		cout << "[:";
		for (int i=0; i<p; i++) {
			cout << "|";
		}
		cout << ":]" << endl;
	}
}

int countInv(int[] a, int[] b) {
	int c = 0;
	
	for (int i = 0; i < a.length; i++) {
		if (a[i] != b[i]) {
			c++;
			int ind = -1;
			for (int j = i+1; j < b.length; j++) {
				if (a[i] == b[j]) {
					ind = j;
				}
			}
			
			if (ind == -1)
				return a.length+1;
			
			int temp = b[i];
			b[i] = b[ind];
			b[ind] = temp;
		}
	}
	
	return c;
}