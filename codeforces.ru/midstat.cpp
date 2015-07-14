// Srednestat.elementy
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;

//~ int main() {
main() {
	int all;
	cin >> all;
	
	vector<int> arr(all, 0);
	int max = 0;
	for (int i = 0; i < all; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		max += num;
	}
	
	vector<int> res;
	for (int i = 0; i < arr.size(); i++) {
		int div = (max - arr[i]) / (all - 1);
		int mod = (max - arr[i]) % (all - 1);
		if ( div == arr[i] && mod == 0) {
			res.push_back(i+1);
			//~ cout << "yes: " << arr[i] << endl;
		}
	}
	
	if (res.size() > 0) {
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
	}
	else
		cout << 0;
	
	//~ return 0;
}