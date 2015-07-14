// HQ9+
#include <iostream>
#include <string>
using namespace std;

int main() {	
  string input;
  getline (cin, input);
  string res = "NO";

	//~ input = "HQ9++";
  for (int i = 0; i < input.size(); i++) {
    int c = (int) input[i];
    if ( c == 72 || c == 81 || c == 57) {
      cout << "YES" << endl;
      return 0;
    }
	  //~ cout << input[i] << (int) input[i] << endl;
  }
  cout << "NO" << endl;
  
  return 0;
}
