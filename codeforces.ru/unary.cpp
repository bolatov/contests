// Unary
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	
	string in;
	getline (cin, in);
	//~ in = ",.";
	//~ in = "++++[>,.<-]";

	string bin = "";
	for (int i = 0; i < in.size(); i++) {
		char c = in[i];
		
		if ( c == '>' )		bin += "1000";
		else if (c == '<')	bin += "1001";
		else if (c == '+')	bin += "1010";
		else if (c == '-')	bin += "1011";
		else if (c == '.')	bin += "1100";
		else if (c == ',')	bin += "1101";
		else if (c == '[')	bin += "1110";
		else if (c == ']')	bin += "1111";
	}
	
	//~ cout << bin << endl;
	
	long res = 0;
	for (int i = 0; i < bin.size(); i++) {
		if (bin[i] == '1')
			res += pow(2, bin.size() - 1 - i);
	}
	cout << "res: " << res << endl;
	
	cout << (res + 1000003) % 1000003;

	return 0;
}