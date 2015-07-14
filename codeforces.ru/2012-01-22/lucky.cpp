// Srednestat.elementy
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;

//~ int main() {
main() {
	int n;
	cin >> n;
	char num[n];
	cin >> num;
	
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n/2; i++) {
		char c1 = num[i];
		char c2 = num[i + n/2];
		
		if ( (c1 != '4' && c1 != '7') || (c2 != '4' && c2 != '7') ) {
//			cout << c1 << " : " << c2;
	//		cout << endl;
			cout << "NO";
			return 0;
		}
		
		sum1 += c1;
		sum2 += c2;
	}
	
	if (sum1 == sum2)
		cout << "YES";
	else
		cout << "NO";
		
	cout << endl;
}
