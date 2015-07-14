#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)

typedef vector<int>    VI;


using namespace std;

std::string int2str( int n )
{
	std::ostringstream result;
	result << n;
	return result.str();
}

int str2int( const std::string& s )
{
	int result;
	std::istringstream ss( s );
	ss >> result;
	if (!ss) throw std::invalid_argument( "StrToInt" );
	return result;
}

// Problem 250
class TheNumberGameDivTwo {
public:
	string find(int n) {
		set<int> primes = getPrimeNumbers(1000);
		// std::set<int>::iterator it;
		
		// std::cout << "primes contains:";
		// for (it=primes.begin(); it!=primes.end(); ++it)
		// 	std::cout << ' ' << *it;
		// std::cout << '\n';


		if (primes.find(n) != primes.end() || n <= 2) {
			return "Brus";
		}
		printf("here\n");
		FOR(i, 2, n-1) {
			if (n % i == 0) {
				printf("n=%d, i=%d\n", n,i);
				int val = n-i;
				if (primes.find(val) != primes.end()) {
					return "John";
				}

			}
		}

		return "Brus";
	}
private:
	set<int> getPrimeNumbers(int UPPER) {
		list<int> primeNumbers;
		for (int i = 2; i < UPPER; i++) {
			primeNumbers.push_back(i);
		}

		for (list<int>::iterator it=primeNumbers.begin(); it != primeNumbers.end(); ++it) {
			list<int>::iterator it1 = it;
			it1++;
			while (it1 != primeNumbers.end()) {
				if (*it1 % *it == 0)	
					it1 = primeNumbers.erase(it1);
				else
					it1++;
			}
		}

		set<int> primes;
		for (list<int>::iterator it=primeNumbers.begin(); it != primeNumbers.end(); ++it) {
			// primes.push_back(*it);
			primes.insert(*it);
		}

		return primes;
	}
};

int main() {

	TheNumberGameDivTwo sp;
	cout << sp.find(6) << endl;
	return 0;
}    	