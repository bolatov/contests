#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main(void)
{
	string line;
	ifstream infile ("input.txt");
	if (infile.is_open())
	{
		while ( infile.good() )
		{
			getline (infile, line);
			
		}
	}
	
	return 0;
}
