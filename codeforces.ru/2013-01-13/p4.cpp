#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

double factorial(int n)
{
  double result = 1;
  for (int k=n; k > 1; k--)
  {
    result *= k; 
  }
  return result;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr_in(n, 0);
	vector<int> pos2num(50, 0);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		pos2num[i] = num;
		arr_in[i] = i;
	}

	int p;
	cin >> p;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		if (arr_in[i] <= p) {
			arr.push_back(pos2num[arr_in[i]]);
		}
	}

	// test
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	// end test

	double res = 0;
	do {
		int sum = 0, people = 0;
		for (int i = 0; i < n; i++) {
			sum += pos2num[arr[i]];
			if (sum > p)	break;
			else 			people++;				
		}
		res += people;

		// // test
		// for (int i = 0; i < n; i++) {
		// 	cout << arr[i] << " ";
		// }
		// cout << " -- " << people << endl;
		// end test
	} while ( next_permutation(arr.begin(), arr.end()));

	printf("%.10f\n", res / factorial(n));
}