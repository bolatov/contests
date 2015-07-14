#include <list>
#include <vector>

//
// Returns a vector with prime numbers in specified range
//
vector<int> getPrimeNumbers(int, LOWER, int UPPER) {
	list<int> primeNumbers;
	for (int i = LOWER; i < UPPER; i++) {
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

	vector<int> primes;
	for (list<int>::iterator it=primeNumbers.begin(); it != primeNumbers.end(); ++it) {
		primes.push_back(*it);
	}

	return primes;
}

//
// Creates a mapping of how many increments to make a number prime
// e.g. 3 -> 0
// e.g. 8 -> 3		(next prime number to 8 is 11, so 11-8=3)
//
vector<int> getMapping(vector<int> primeNumbers) {
	int UPPER = primeNumbers[primeNumbers.size()-1];
	vector<int> stepsVector(UPPER, 0);
	int j = 0;
	for (int i = 1; i < UPPER; i++) {
		for (; j < primeNumbers.size(); j++) {
			if (primeNumbers[j] >= i) {
				stepsVector[i] = primeNumbers[j] - i;
				break;
			}
		}
	}
	return stepsVector;
}