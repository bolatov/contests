// Turing tape
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	
	string input;
	getline (cin, input);
	int last = 0;
	for (int i = 0; i < input.size(); i++) {
		int num = (int) input[i]; // ascii_value
		string repr = "";
		for (int j = 0; j < 8; j++) {
			if (num & (1 << j))
				repr += '1';
			else
				repr += '0';
		}
		
		int mirrd = 0; // mirrored representation
		for (int j = repr.length()-1; j >= 0; j--) {
			if ( repr[j] == '1' )
				mirrd += pow(2, repr.length() - 1 - j);
		}
		
		
		
		cout << (last - mirrd + 256) % 256 << endl;
		last = mirrd;
	}

	return 0;
}